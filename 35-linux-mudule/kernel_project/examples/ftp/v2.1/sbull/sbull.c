/*
 * sbull.c -- the Simple Block Utility
 *
 * Tested with 2.1.43 on the x86
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#define __NO_VERSION__ /* don't define kernel_verion in module.h */
#include <linux/module.h>
#include <linux/version.h>

char kernel_version [] = UTS_RELEASE;

#include <linux/sched.h>
#include <linux/kernel.h> /* printk() */
#include <linux/malloc.h> /* kmalloc() */
#include <linux/fs.h>     /* everything... */
#include <linux/errno.h>  /* error codes */
#include <linux/timer.h>
#include <linux/types.h>  /* size_t */
#include <linux/fcntl.h>        /* O_ACCMODE */
#include <linux/hdreg.h>  /* HDIO_GETGEO */

#include <asm/system.h>   /* cli(), *_flags */
#include <asm/segment.h>  /* put_user */

#include "sysdep-2.1.h" /* at least for add_timer */

#define MAJOR_NR sbull_major /* force definitions on in blk.h */
int sbull_major; /* must be declared before including blk.h */

#define DEVICE_NR(device) MINOR(device)   /* sbull has no partition bits */
#define DEVICE_NAME "sbull"               /* name for messaging */
#define DEVICE_INTR sbull_intrptr         /* pointer to the bottom half */
#define DEVICE_NO_RANDOM                  /* no entropy to contribute */

#define DEVICE_OFF(d) /* do-nothing */

#if LINUX_VERSION_CODE < 0x10324 /* 1.3.36 */
#  include <linux/../../drivers/block/blk.h>
#else
#  include <linux/blk.h>
#endif

#include "sbull.h"        /* local definitions */

/*
 * Non-prefixed symbols are static. They are meant to be assigned at
 * load time. Prefixed symbols are not static, so they can be used in
 * debugging. They are hidden anyways by register_symtab() unless
 * SBULL_DEBUG is defined.
 */
static int major    = SBULL_MAJOR;
static int devs     = SBULL_DEVS;
static int rahead   = SBULL_RAHEAD;
static int size     = SBULL_SIZE;
static int blksize  = SBULL_BLKSIZE;
static int hardsect = SBULL_HARDSECT;

int sbull_devs, sbull_rahead, sbull_size;
int sbull_blksize, sbull_hardsect;

MODULE_PARM(major,"i");
MODULE_PARM(devs,"i");
MODULE_PARM(rahead,"i");
MODULE_PARM(size,"i");
MODULE_PARM(blksize,"i");
MODULE_PARM(hardsect,"i");

/* The following items are obtained through kmalloc() in init_module() */

Sbull_Dev *sbull_devices = NULL;
int *sbull_blksizes = NULL;
int *sbull_sizes = NULL;
int *sbull_hardsects = NULL;

int sbull_revalidate(kdev_t i_rdev);


/*
 * Open and close
 */

int sbull_open (struct inode *inode, struct file *filp)
{
    Sbull_Dev *dev; /* device information */
    int num = MINOR(inode->i_rdev);

    if (num >= sbull_devs) return -ENODEV;
    dev = sbull_devices + num;

    /* kill the timer associated to the device: it might be active */
    del_timer(&dev->timer);

    /* revalidate on first open and fail if no data is there */
    if (!dev->usage) {
        check_disk_change(inode->i_rdev);
        if (!dev->data)
            return -ENOMEM;
    }
    dev->usage++;
    MOD_INC_USE_COUNT;
    return 0;          /* success */
}

release_t sbull_release (struct inode *inode, struct file *filp)
{
    Sbull_Dev *dev = sbull_devices + MINOR(inode->i_rdev);

    dev->usage--;
    /*
     * If the device is closed for the last time, start a timer
     * to release RAM in half a minute. The function and argument
     * for the timer have been setup in init_module()
     */
    if (!dev->usage) {
        dev->timer.expires = jiffies + 30 * HZ;
        add_timer(&dev->timer);
        /* but flush it right now */
        fsync_dev(inode->i_rdev);
        invalidate_buffers(inode->i_rdev);
    }
    MOD_DEC_USE_COUNT;
    release_return(0);
}


/*
 * The timer function. As argument it receives the device
 */
void sbull_expires(unsigned long data)
{
    Sbull_Dev *dev = (Sbull_Dev *)data;

    if (dev->usage || !dev->data) {
        printk(KERN_WARNING "sbull: timer mismatch for device %i\n",
               dev - sbull_devices);
        return;
    }
    PDEBUG("freeing device %i\n",dev - sbull_devices);
    vfree(dev->data);
    dev->data=0;
    return;
}    

/*
 * The ioctl() implementation
 */

int sbull_ioctl (struct inode *inode, struct file *filp,
                 unsigned int cmd, unsigned long arg)
{
    int err, size;
    struct hd_geometry *geo = (struct hd_geometry *)arg;

    PDEBUG("ioctl 0x%x 0x%lx\n", cmd, arg);
    switch(cmd) {

      case BLKGETSIZE:
        /* Return the device size, expressed in sectors */
        if (!arg) return -EINVAL; /* NULL pointer: not valid */
        err=verify_area_20(VERIFY_WRITE, (long *) arg, sizeof(long));
        if (err) return err;
        PUT_USER_RET ( 1024* sbull_sizes[MINOR(inode->i_rdev)]
                   / sbull_hardsects[MINOR(inode->i_rdev)],
                     (long *) arg, -EFAULT);
        return 0;

      case BLKFLSBUF: /* flush */
        if (!suser()) return -EACCES; /* only root */
        fsync_dev(inode->i_rdev);
        invalidate_buffers(inode->i_rdev);
        return 0;

      case BLKRAGET: /* return the readahead value */
        if (!arg)  return -EINVAL;
        err = verify_area_20(VERIFY_WRITE, (long *) arg, sizeof(long));
        if (err) return err;
        PUT_USER_RET(read_ahead[MAJOR(inode->i_rdev)], (long *)arg, -EFAULT);
        return 0;

      case BLKRASET: /* set the readahead value */
        if (!suser()) return -EACCES;
        if (arg > 0xff) return -EINVAL; /* limit it */
        read_ahead[MAJOR(inode->i_rdev)] = arg;
        return 0;

      case BLKRRPART: /* re-read partition table: can't do it */
        return -EINVAL;

      RO_IOCTLS(inode->i_rdev, arg); /* the default RO operations */

      case HDIO_GETGEO:
        /*
         * get geometry: we have to fake one...  trim the size to a
         * multiple of 64 (32k): tell we have 16 sectors, 4 heads,
         * whatever cylinders. Tell also that data starts at sector. 4.
         */
        size = sbull_size * 1024 / sbull_hardsect;
        size &= ~0x3f; /* multiple of 64 */
        if (geo==NULL) return -EINVAL;
        err = verify_area_20(VERIFY_WRITE, geo, sizeof(*geo));
        if (err) return err;
        PUT_USER_RET(size >> 6, &geo->cylinders, -EFAULT);
        PUT_USER_RET(        4, &geo->heads,     -EFAULT);
        PUT_USER_RET(       16, &geo->sectors,   -EFAULT);
        PUT_USER_RET(        4, &geo->start,     -EFAULT);
        return 0;
    }

    return -EINVAL; /* unknown command */
}

/*
 * Support for removable devices
 */

int sbull_check_change(kdev_t i_rdev)
{
    int minor = MINOR(i_rdev);
    Sbull_Dev *dev = sbull_devices + minor;

    if (minor >= sbull_devs) /* paranoid */
        return 0;

    PDEBUG("check_change for dev %i\n",minor);

    if (dev->data)
        return 0; /* still valid */
    return 1; /* expired */
}


int sbull_revalidate(kdev_t i_rdev)
{
    Sbull_Dev *dev = sbull_devices + MINOR(i_rdev);

    PDEBUG("revalidate for dev %i\n",MINOR(i_rdev));
    if (dev->data)
        return 0;
    dev->data = vmalloc(dev->size);
    if (!dev->data)
        return -ENOMEM;
    return 0;
}

/*
 * The file operations
 */

struct file_operations sbull_fops = {
    NULL,          /* lseek: default */
    block_read,
    block_write,
    NULL,          /* sbull_readdir */
    NULL,          /* sbull_select */
    sbull_ioctl,
    NULL,          /* sbull_mmap */
    sbull_open,
    sbull_release,
    block_fsync,
    NULL,          /* sbull_fasync */
    sbull_check_change,
    sbull_revalidate
};

/*
 * Block-driver specific functions
 */

#ifdef SBULL_EMPTY_REQUEST
/*
 * This empty request function just prints the interesting items
 * of the current request. The sectors affected by the request
 * are printed as <first-sector>-<number-of-sectors>.
 */
void sbull_request(void)
{
    while(1) {
        INIT_REQUEST;
        printk("request %p: cmd %i sec %li (nr. %li), next %p\n", CURRENT,
               CURRENT->cmd,
               CURRENT->sector,
               CURRENT->current_nr_sectors,
               CURRENT->next);
        end_request(1); /* success */
    }
}
#else
void sbull_request(void)
{
    Sbull_Dev *device;
    u8 *ptr;
    int size;

    while(1) {
        INIT_REQUEST;

        /* Check if the minor number is in range */
        if (DEVICE_NR(CURRENT_DEV) > sbull_devs) {
            static int count = 0;
            if (count++ < 5) /* print the message at most five times */
                printk(KERN_WARNING "sbull: request for unknown device\n");
            end_request(0);
            continue;
        }

        /* pointer to device structure, from the global array */
        device = sbull_devices + DEVICE_NR(CURRENT_DEV);
        ptr = device->data + CURRENT->sector * sbull_hardsect;
        size = CURRENT->current_nr_sectors * sbull_hardsect;
        if (ptr + size > device->data + sbull_blksize*sbull_size) {
            static int count = 0;
            if (count++ < 5)
                printk(KERN_WARNING "sbull: request past end of device\n");
            end_request(0);
            continue;
        }

        switch(CURRENT->cmd) {
          case READ:
            memcpy(CURRENT->buffer, ptr, size); /* from sbull to buffer */
            break;
          case WRITE:
            memcpy(ptr, CURRENT->buffer, size); /* from buffer to sbull */
            break;
          default:
            /* can't happen */
            end_request(0);
            continue;
        }

        end_request(1); /* success */
    }
}
#endif /* SBULL_EMPTY_REQUEST */

/*
 * Finally, the module stuff
 */

int init_module(void)
{
    int result, i;

    /*
     * Copy the (static) cfg variables to public prefixed ones to allow
     * snoozing with a debugger.
     */

    sbull_major    = major;
    sbull_devs     = devs;
    sbull_rahead   = rahead;
    sbull_size     = size;
    sbull_blksize  = blksize;
    sbull_hardsect = hardsect;

    /* Hardsect can't be changed :( */
    if (hardsect != 512) {
        printk(KERN_ERR "sbull: can't change hardsect size\n");
        hardsect = sbull_hardsect = 512;
    }

    /*
     * Register your major, and accept a dynamic number
     */
    result = register_blkdev(sbull_major, "sbull", &sbull_fops);
    if (result < 0) {
        printk(KERN_WARNING "sbull: can't get major %d\n",sbull_major);
        return result;
    }
    if (sbull_major == 0) sbull_major = result; /* dynamic */
    major = sbull_major; /* Use `major' later on to save typing */

    /*
     * Assign the other needed values: request, rahead, size, blksize,
     * hardsect. All the minor devices feature the same value.
     * Note that `sbull' defines all of them to allow testing non-default
     * values. A real device could well avoid setting values in global
     * arrays if it uses the default values.
     */

    blk_dev[major].request_fn = sbull_request;
    read_ahead[major] = sbull_rahead;
    result = -ENOMEM; /* for the possible errors */

    sbull_sizes = kmalloc(sbull_devs * sizeof(int), GFP_KERNEL);
    if (!sbull_sizes)
        goto fail_malloc;
    for (i=0; i < sbull_devs; i++) /* all the same size */
        sbull_sizes[i] = sbull_size;
    blk_size[major]=sbull_sizes;

    sbull_blksizes = kmalloc(sbull_devs * sizeof(int), GFP_KERNEL);
    if (!sbull_blksizes)
        goto fail_malloc;
    for (i=0; i < sbull_devs; i++) /* all the same blocksize */
        sbull_blksizes[i] = sbull_blksize;
    blksize_size[major]=sbull_blksizes;

    sbull_hardsects = kmalloc(sbull_devs * sizeof(int), GFP_KERNEL);
    if (!sbull_hardsects)
        goto fail_malloc;
    for (i=0; i < sbull_devs; i++) /* all the same hardsect */
        sbull_hardsects[i] = sbull_hardsect;
    hardsect_size[major]=sbull_hardsects;
    
    /* 
     * allocate the devices -- we can't have them static, as the number
     * can be specified at load time
     */

    sbull_devices = kmalloc(sbull_devs * sizeof (Sbull_Dev), GFP_KERNEL);
    if (!sbull_devices)
        goto fail_malloc;
    memset(sbull_devices, 0, sbull_devs * sizeof (Sbull_Dev));
    for (i=0; i < sbull_devs; i++) {
        /* data and usage remain zeroed */
        sbull_devices[i].size = 1024 * sbull_size;
        init_timer(&(sbull_devices[i].timer));
        sbull_devices[i].timer.data = (unsigned long)(sbull_devices+i);
        sbull_devices[i].timer.function = sbull_expires;
    }

#ifndef SBULL_DEBUG
    REGISTER_SYMTAB(NULL); /* otherwise, leave global symbols visible */
#endif

    return 0; /* succeed */

  fail_malloc:
    read_ahead[major] = 0;
    if (sbull_sizes) kfree(sbull_sizes);
    blk_size[major] = NULL;
    if (sbull_blksizes) kfree(sbull_blksizes);
    blksize_size[major] = NULL;
    if (sbull_hardsects) kfree(sbull_hardsects);
    hardsect_size[major] = NULL;
    if (sbull_devices) kfree(sbull_devices);

    unregister_chrdev(major, "sbull");
    return result;
}

void cleanup_module(void)
{
    int i;

    /* first of all, flush it all and reset all the data structures */


    for (i=0; i<sbull_devs; i++)
        fsync_dev(MKDEV(sbull_major, i)); /* flush the devices */

    blk_dev[major].request_fn = NULL;
    read_ahead[major] = 0;
    kfree(blk_size[major]);
    blk_size[major] = NULL;
    kfree(blksize_size[major]);
    blksize_size[major] = NULL;
    kfree(hardsect_size[major]);
    hardsect_size[major] = NULL;

    /* finally, the usual cleanup */

    unregister_blkdev(major, "sbull");

    for (i=0; i < sbull_devs; i++) {
        if (sbull_devices[i].data)
            vfree(sbull_devices[i].data);
        del_timer(&sbull_devices[i].timer);
    }
    kfree(sbull_devices);
}






