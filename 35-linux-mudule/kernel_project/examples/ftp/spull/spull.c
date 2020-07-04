/*
 * spull.c -- the simple partitionable utility
 *
 * Tested with 2.0 on the x86, Sparc
 *********/

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

#define MAJOR_NR spull_major /* force definitions on in blk.h */
int spull_major; /* must be known to the compiler */

#define SPULL_SHIFT 4                         /* max 16 partitions  */
#define SPULL_MAXNRDEV 4                      /* max 4 device units */
#define DEVICE_NR(device) (MINOR(device)>>SPULL_SHIFT)
#define DEVICE_NAME "pd"                      /* name for messaging */
#define DEVICE_INTR spull_intrptr             /* pointer to the bottom half */
#define DEVICE_NO_RANDOM                      /* no entropy to contribute */

#define DEVICE_OFF(d) /* do-nothing */

#if LINUX_VERSION_CODE < 0x10324 /* 1.3.36 */
#  include <linux/../../drivers/block/blk.h>
#else
#  include <linux/blk.h>
#endif

#include "spull.h"        /* local definitions */

#include "sysdep.h"

/* Partitionable modules can't load before 1.3.7 */
#if LINUX_VERSION_CODE < VERSION_CODE(1,3,7)
#error "This modules requires at least Linux 1.3.7 to load"
#endif

/*
 * Non-prefixed symbols are static. They are meant to be assigned at
 * load time. Prefixed symbols are not static, so they can be used in
 * debugging. They are hidden anyways by register_symtab() unless
 * SPULL_DEBUG is defined.
 */
static int major    = SPULL_MAJOR;
static int devs     = SPULL_DEVS;
static int rahead   = SPULL_RAHEAD;
static int size     = SPULL_SIZE;
static int irq      = 0; /* no interrupt driven by default */

int spull_devs, spull_rahead, spull_size, spull_irq;

/* The following items are obtained through kmalloc() in init_module() */

Spull_Dev *spull_devices = NULL;
int *spull_blksizes = NULL;
int *spull_sizes = NULL;

int spull_revalidate(kdev_t i_rdev);

/*
 * Our generic hard disk
 */

struct gendisk spull_gendisk = {
    0,                /* Major number, assigned after dynamic retrieval */
    "pd",             /* Major name */
    SPULL_SHIFT,      /* Bits to shift to get real from partition */
    1 << SPULL_SHIFT, /* Number of partitions per real */
    SPULL_MAXNRDEV,   /* Maximum nr of devices */
    NULL,             /* No init function (isn't called, anyways) */
    NULL,             /* Partition array, allocated by init_module */
    NULL,             /* Block sizes, allocated by init_module */
    0,                /* Number of units: set by init_module */
    NULL,             /* "real_devices" pointer: not used */
    NULL              /* Next */
};

struct hd_struct *spull_partitions = NULL;


/*
 * Open and close
 */

int spull_open (struct inode *inode, struct file *filp)
{
    Spull_Dev *dev; /* device information */
    int num = DEVICE_NR(inode->i_rdev); /* the real device */

    if (num >= spull_devs) return -ENODEV;
    dev = spull_devices + num;

    /* and use filp->private_data to point to the device data */
    filp->private_data = dev;

    /* kill the timer associated to the device: it might be active */
    del_timer(&dev->timer);

    /*
     * If no data area is there, allocate it. Clear its head as
     * well to prevent memory corruption due to bad partition info.
     */
    if (!dev->data) {
        dev->data = vmalloc(dev->size);
        memset(dev->data,0,2048);
    }
    if (!dev->data)
        return -ENOMEM;

    dev->usage++;
    MOD_INC_USE_COUNT;
    return 0;          /* success */
}

void spull_release (struct inode *inode, struct file *filp)
{
    Spull_Dev *dev = spull_devices + DEVICE_NR(inode->i_rdev);

    dev->usage--;
    /*
     * Leave one minute timeout before deallocating the device.
     */
    if (!dev->usage) {
        dev->timer.expires = jiffies + 60 * HZ;
        add_timer(&dev->timer);
        /* but flush it right now */
        fsync_dev(inode->i_rdev);
        invalidate_buffers(inode->i_rdev);
    }
    fsync_dev(inode->i_rdev);
    invalidate_buffers(inode->i_rdev);
    MOD_DEC_USE_COUNT;
}

/*
 * The timer function. As argument it receives the device
 */
void spull_expires(unsigned long data)
{
    Spull_Dev *dev = (Spull_Dev *)data;

    if (dev->usage || !dev->data) {
        printk(KERN_WARNING "spull: timer mismatch for device %i\n",
               dev - spull_devices);
        return;
    }
    PDEBUG("freeing device %i\n",dev - spull_devices);
    vfree(dev->data);
    dev->data=0;
    return;
}    

/*
 * The ioctl() implementation
 */

int spull_ioctl (struct inode *inode, struct file *filp,
                 unsigned int cmd, unsigned long arg)
{
    int err, size;
    struct hd_geometry *geo = (struct hd_geometry *)arg;

    PDEBUG("ioctl 0x%x 0x%lx\n", cmd, arg);
    switch(cmd) {

      case BLKGETSIZE:
        /* Return the device size, expressed in sectors */
        if (!arg) return -EINVAL; /* NULL pointer: not valid */
        err=verify_area(VERIFY_WRITE, (long *) arg, sizeof(long));
        if (err) return err;
        size = spull_gendisk.part[MINOR(inode->i_rdev)].nr_sects;
        put_user (size, (long *) arg);
        return 0;

      case BLKFLSBUF: /* flush */
        if (!suser()) return -EACCES; /* only root */
        fsync_dev(inode->i_rdev);
        invalidate_buffers(inode->i_rdev);
        return 0;

      case BLKRAGET: /* return the readahead value */
        if (!arg)  return -EINVAL;
        err = verify_area(VERIFY_WRITE, (long *) arg, sizeof(long));
        if (err) return err;
        put_user(read_ahead[MAJOR(inode->i_rdev)],(long *) arg);
        return 0;

      case BLKRASET: /* set the readahead value */
        if (!suser()) return -EACCES;
        if (arg > 0xff) return -EINVAL; /* limit it */
        read_ahead[MAJOR(inode->i_rdev)] = arg;
        return 0;

      case BLKRRPART: /* re-read partition table: fake a disk change */
        return spull_revalidate(inode->i_rdev);

      RO_IOCTLS(inode->i_rdev, arg); /* the default RO operations */

      case HDIO_GETGEO:
        /*
         * get geometry: we have to fake one...  trim the size to a
         * multiple of 64 (32k): tell we have 16 sectors, 4 heads,
         * whatever cylinders. Tell also that data starts at sector 4.
         */
        size = spull_size * 2; /* 2 sectors per kilobyte */
        size &= ~0x3f; /* multiple of 64 */
        if (geo==NULL) return -EINVAL;
        err = verify_area(VERIFY_WRITE, geo, sizeof(*geo));
        if (err) return err;
        put_user(size >> 6, &geo->cylinders);
        put_user(        4, &geo->heads);
        put_user(       16, &geo->sectors);
        put_user(        4, &geo->start);
        return 0;
    }

    return -EINVAL; /* unknown command */
}

/*
 * Support for removable devices
 */

int spull_check_change(kdev_t i_rdev)
{
    int devnr = DEVICE_NR(i_rdev);
    Spull_Dev *dev = spull_devices + devnr;

    if (devnr >= spull_devs) /* paranoid */
        return 0;

    PDEBUG("check_change for dev %i\n",MINOR(i_rdev));

    if (dev->data)
        return 0; /* still valid */
    return 1; /* expired */
}


int spull_revalidate(kdev_t i_rdev)
{
    /* first partition, # of partitions */
    int part1 = (DEVICE_NR(i_rdev) << SPULL_SHIFT) + 1;
    int npart = (1 << SPULL_SHIFT) -1;

    /* first clear old partition information */
    memset(spull_gendisk.sizes+part1, 0, npart*sizeof(int));
    memset(spull_gendisk.part +part1, 0, npart*sizeof(struct hd_struct));

    /* then fill new info */
    printk(KERN_INFO "Spull partition check: ");
    resetup_one_dev(&spull_gendisk, DEVICE_NR(i_rdev));
    return 0;
}

/*
 * The file operations
 */

struct file_operations spull_fops = {
    NULL,          /* lseek: default */
    block_read,
    block_write,
    NULL,          /* spull_readdir */
    NULL,          /* spull_select */
    spull_ioctl,
    NULL,          /* spull_mmap */
    spull_open,
    spull_release,
    block_fsync,
    NULL,          /* spull_fasync */
    spull_check_change,
    spull_revalidate
};

/*
 * Block-driver specific functions
 */

void spull_request(void)
{
    Spull_Dev *device;
    u8 *ptr;
    int size, minor, devnr;

    while(1) {
        INIT_REQUEST;

        devnr = DEVICE_NR(CURRENT_DEV);
        minor = MINOR(CURRENT_DEV);

        /* Check if the minor number is in range */
        if (devnr > spull_devs) {
            static int count = 0;
            if (count++ < 5) /* print the message at most five times */
                printk(KERN_WARNING "spull: request for inexistent device\n");
            end_request(0);
            continue;
        }

        PDEBUGG("cmd %c for minor 0x%02x ( sec%li)\n",
               CURRENT->cmd==READ ? 'r' : 'w', minor,CURRENT->sector);
        device = spull_devices + devnr;

	/* the sector size is 512 bytes */
        ptr = device->data +
            512 * (spull_partitions[minor].start_sect + CURRENT->sector);
        size = CURRENT->current_nr_sectors * 512;

        if (CURRENT->sector + CURRENT->current_nr_sectors >
                spull_gendisk.part[minor].nr_sects) {
            printk(KERN_WARNING "spull: request past end of device\n");
            end_request(0);
            continue;
        }

        switch(CURRENT->cmd) {
          case READ:
            memcpy(CURRENT->buffer, ptr, size); /* from spull to buffer */
            break;
          case WRITE:
            memcpy(ptr, CURRENT->buffer, size); /* from buffer to spull */
            break;
          default:
            /* can't happen */
            end_request(0);
            continue;
        }

        end_request(1); /* success */
    }
}

/*
 * The fake interrupt-driven request
 */
struct timer_list spull_timer; /* the engine for async invocation */

void spull_irqdriven_request(void)
{
    Spull_Dev *device;
    u8 *ptr;
    int size, minor, devnr;
    /*
     * Check for errors and start data transfer for the current request.
     * The spull ramdisk performs the transfer right ahead,
     * but delays acknolegment using a kernel timer.
     */
    while(1) {
        INIT_REQUEST;

        devnr = DEVICE_NR(CURRENT_DEV);
        minor = MINOR(CURRENT_DEV);

        /* then the core of the function is unchanged.... */

        /* Check if the minor number is in range */
        if (devnr > spull_devs) {
            static int count = 0;
            if (count++ < 5) /* print the message at most five times */
                printk(KERN_WARNING "spull: request for inexistent device\n");
            end_request(0);
            continue;
        }

        PDEBUGG("cmd %c for minor 0x%02x ( sec%li)\n",
               CURRENT->cmd==READ ? 'r' : 'w', minor,CURRENT->sector);
        device = spull_devices + devnr;

        ptr = device->data +
            512 * (spull_partitions[minor].start_sect + CURRENT->sector);
        size = CURRENT->current_nr_sectors * 512;

        if (CURRENT->sector + CURRENT->current_nr_sectors >
                spull_gendisk.part[minor].nr_sects) {
            printk(KERN_WARNING "spull: request past end of device\n");
            end_request(0);
            continue;
        }


	/* ... and this is how the function completes: xfer now ... */
        switch(CURRENT->cmd) {
          case READ:
            memcpy(CURRENT->buffer, ptr, size);
            break;
          case WRITE:
            memcpy(ptr, CURRENT->buffer, size);
            break;
          default: /* should't happen */
            end_request(0);
            continue;
        }

        /* ... and wait for the timer to expire -- no end_request(1) */
        spull_timer.expires = jiffies + spull_irq;
        add_timer(&spull_timer);
        return;
    }
}

/* this is invoked when the timer expires */
void spull_interrupt(unsigned long unused)
{
     /*
      * arg to end_request(), default to success, a real device might
      * signal a failure, if it detects one
      */
    int fulfilled = 1;

    end_request(fulfilled);    /* done one */

    if (CURRENT) /* more of them? */
        spull_irqdriven_request();  /* schedule the next */
}

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

    spull_major    = major;
    spull_devs     = devs;
    spull_rahead   = rahead;
    spull_size     = size;

    /*
     * Register your major, and accept a dynamic number
     */
    result = register_blkdev(spull_major, "spull", &spull_fops);
    if (result < 0) {
        printk(KERN_WARNING "spull: can't get major %d\n",spull_major);
        return result;
    }
    if (spull_major == 0) spull_major = result; /* dynamic */
    major = spull_major; /* Use `major' later on to save typing */

    spull_gendisk.major = major; /* was unknown at load time */

    /* 
     * allocate the devices -- we can't have them static, as the number
     * can be specified at load time
     */

    spull_devices = kmalloc(spull_devs * sizeof (Spull_Dev), GFP_KERNEL);
    if (!spull_devices)
        goto fail_malloc;
    memset(spull_devices, 0, spull_devs * sizeof (Spull_Dev));
    for (i=0; i < spull_devs; i++) {
        /* data and usage remain zeroed */
        spull_devices[i].size = 1024 * spull_size;
        init_timer(&(spull_devices[i].timer));
        spull_devices[i].timer.data = (unsigned long)(spull_devices+i);
        spull_devices[i].timer.function = spull_expires;
    }

    blk_dev[major].request_fn = spull_request;

    read_ahead[major] = spull_rahead;

    result = -ENOMEM; /* for the possible errors */

    /* Prepare the `size' array and zero it. */
    spull_sizes = kmalloc( (spull_devs << SPULL_SHIFT) * sizeof(int),
                          GFP_KERNEL);
    if (!spull_sizes)
        goto fail_malloc;

    /* Start with zero-sized partitions, and correctly sized units */
    memset(spull_sizes, 0, (spull_devs << SPULL_SHIFT) * sizeof(int));
    for (i=0; i< spull_devs; i++)
        spull_sizes[i<<SPULL_SHIFT] = spull_size;
    blk_size[MAJOR_NR] = spull_gendisk.sizes = spull_sizes;

    /* Allocate the partitions, and refer the array in spull_gendisk. */
    spull_partitions = kmalloc( (spull_devs << SPULL_SHIFT) *
                               sizeof(struct hd_struct), GFP_KERNEL);
    if (!spull_partitions)
        goto fail_malloc;

    memset(spull_partitions, 0, (spull_devs << SPULL_SHIFT) *
           sizeof(struct hd_struct));
    /* fill whole-disk entries */
    for (i=0; i < spull_devs; i++) {
        /* start_sect is already 0, and sects are 512 bytes long */
        spull_partitions[i << SPULL_SHIFT].nr_sects = 2 * spull_size;
    }
    spull_gendisk.part = spull_partitions;

#if 0
    /*
     * Well, now a *real* driver should call resetup_one_dev().
     * Avoid it here, as there's no allocated data in spull yet.
     */
    for (i=0; i< spull_devs; i++) {
        printk(KERN INFO "Spull partition check: ");
        resetup_one_dev(&spull_gendisk, i);
    }
#endif

    /* dump the partition table to see it */
    for (i=0; i < spull_devs << SPULL_SHIFT; i++)
        PDEBUGG("part %i: beg %lx, size %lx\n", i,
               spull_partitions[i].start_sect,
               spull_partitions[i].nr_sects);

#ifndef SPULL_DEBUG
    register_symtab(NULL); /* otherwise, leave global symbols visible */
#endif

    /*
     * Allow interrupt-driven operation, if "irq=" has been specified
     */
    spull_irq = irq; /* copy the static variable to the visible one */
    if (spull_irq) {
        PDEBUG("setting timer\n");
        spull_timer.function = spull_interrupt;
        blk_dev[major].request_fn = spull_irqdriven_request;
    }
    
    return 0; /* succeed */

  fail_malloc:
    read_ahead[major] = 0;
    if (spull_sizes) kfree(spull_sizes);
    blk_size[major] = NULL;
    if (spull_partitions) kfree(spull_partitions);
    if (spull_devices) kfree(spull_devices);

    unregister_chrdev(major, "spull");
    return result;
}

void cleanup_module(void)
{
    int i;

    /* first of all, flush it all and reset all the data structures */

    for (i = 0; i < (spull_devs << SPULL_SHIFT); i++)
        fsync_dev(MKDEV(spull_major, i)); /* flush the devices */
    blk_dev[major].request_fn = NULL;
    read_ahead[major] = 0;
    kfree(blk_size[major]); /* which is gendisk->sizes as well */
    blk_size[major] = NULL;
    kfree(spull_gendisk.part);

    /* finally, the usual cleanup */

    unregister_blkdev(major, "spull");

    for (i=0; i < spull_devs; i++) {
        if (spull_devices[i].data)
            vfree(spull_devices[i].data);
        del_timer(&spull_devices[i].timer);
    }
    kfree(spull_devices);
}






