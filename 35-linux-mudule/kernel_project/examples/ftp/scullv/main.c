/*
 * main.c -- scullv: the scull-virtual char driver
 *
 * Tested with 2.0 on the x86, Sparc
 *
 * Mmap is not available on the Sparc, as pgd_offset etc. are not
 * yet exported to modules. Nonetheless, I've been able to run this
 * code by tweaking the loading mechanism.
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

#include <linux/kernel.h> /* printk() */
#include <linux/malloc.h> /* kmalloc() */
#include <linux/fs.h>     /* everything... */
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>        /* O_ACCMODE */

#include <asm/system.h>   /* cli(), *_flags */
#include <asm/segment.h>  /* memcpy_* put_user and so on */

#include "scullv.h"        /* local definitions */


/*
 * I don't use static symbols here, because register_symtab is called
 */

int scullv_major =   SCULLV_MAJOR;
int scullv_devs =    SCULLV_DEVS;    /* number of bare scullv devices */
int scullv_order =   SCULLV_ORDER;
int scullv_qset =    SCULLV_QSET;

ScullV_Dev *scullv_devices; /* allocated in init_module */

int scullv_trim(ScullV_Dev *dev);

#ifdef SCULLV_USE_PROC /* don't waste space if unused */
/*
 * The proc filesystem: function to read and entry
 */

int scullv_read_procmem(char *buf, char **start, off_t offset,
                   int len, int unused)
{
    int i, j, order, qset;
    ScullV_Dev *d;

    #define LIMIT (PAGE_SIZE-80) /* don't print any more after this size */
    len=0;
    for(i=0; i<scullv_devs; i++) {
        d=&scullv_devices[i];
        order=d->order;  /* retrieve the features of each device */
        qset=d->qset;
        len += sprintf(buf+len,"\nDevice %i: qset %i, order %i, sz %li\n",
                       i, qset, order, (long)(d->size));
        for (; d; d=d->next) { /* scan the list */
            if (len > LIMIT) return len;
            len += sprintf(buf+len,"  item at %p, qset at %p\n",d,d->data);
            if (d->data && !d->next) /* dump only the last item - save space */
                for (j=0; j<qset; j++) {
                    if (len > LIMIT) return len;
                    if (d->data[j])
                        len += sprintf(buf+len,"    % 4i:%8p\n",j,d->data[j]);
                }
        }
    }
    return len;
}

struct proc_dir_entry scullv_proc_entry = {
        0,                 /* low_ino: the inode -- dynamic */
        9, "scullvmem",    /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &scullv_read_procmem,   /* function used to read data */
        /* nothing more */
    };
#endif /* SCULLV_USE_PROC */

/*
 * Open and close
 */

int scullv_open (struct inode *inode, struct file *filp)
{
    int num = MINOR(inode->i_rdev);
    ScullV_Dev *dev; /* device information */

    /*  check the device number */
    if (num >= scullv_devs) return -ENODEV;
    dev = &scullv_devices[num];

    /* now trim to 0 the length of the device if open was write-only */
    if ( (filp->f_flags & O_ACCMODE) == O_WRONLY)
        scullv_trim(dev);

    /* and use filp->private_data to point to the device data */
    filp->private_data = dev;

    MOD_INC_USE_COUNT;
    return 0;          /* success */
}

void scullv_release (struct inode *inode, struct file *filp)
{
    MOD_DEC_USE_COUNT;
}

/*
 * Follow the list 
 */
ScullV_Dev *scullv_follow(ScullV_Dev *dev, int n)
{
    while (n--) {
        if (!dev->next) {
            dev->next = kmalloc(sizeof(ScullV_Dev), GFP_KERNEL);
            memset(dev->next, 0, sizeof(ScullV_Dev));
        }
        dev = dev->next;
        continue;
    }
    return dev;
}

/*
 * Data management: read and write
 */

read_write_t scullv_read (struct inode *inode, struct file *filp,
                char *buf, count_t count)
{
    ScullV_Dev *dev = filp->private_data; /* the first listitem */
    int quantum = PAGE_SIZE << dev->order;
    int qset = dev->qset;
    int itemsize = quantum * qset; /* how many bytes in the listitem */
    unsigned long f_pos = (unsigned long)(filp->f_pos);
    int item, s_pos, q_pos, rest;

    if (f_pos > dev->size)
        return 0;
    if (f_pos + count > dev->size)
        count = dev->size - f_pos;
    /* find listitem, qset index and offset in the quantum */
    item = f_pos / itemsize;
    rest = f_pos % itemsize;
    s_pos = rest / quantum; q_pos = rest % quantum;

    /* follow the list up to the right position (defined elsewhere) */
    dev = scullv_follow(dev, item);

    if (!dev->data)
        return 0; /* don't fill holes */
    if (!dev->data[s_pos])
        return 0;
    if (count > quantum - q_pos)
        count = quantum - q_pos; /* read only up to the end of this quantum */
    memcpy_tofs(buf, dev->data[s_pos]+q_pos, count);
    filp->f_pos += count;
    return count;
}

read_write_t scullv_write (struct inode *inode, struct file *filp,
                const char *buf, count_t count)
{
    ScullV_Dev *dev = filp->private_data;
    ScullV_Dev *dptr;
    int order = dev->order;
    int quantum = PAGE_SIZE << order;
    int qset = dev->qset;
    int itemsize = quantum * qset;
    unsigned long f_pos = (unsigned long)(filp->f_pos);
    int item, s_pos, q_pos, rest;

    /* find listitem, qset index and offset in the quantum */
    item = f_pos / itemsize;
    rest = f_pos % itemsize;
    s_pos = rest / quantum; q_pos = rest % quantum;

    /* follow the list up to the right position */
    dptr = scullv_follow(dev, item);
    if (!dptr->data) {
        dptr->data = kmalloc(qset * sizeof(void *), GFP_KERNEL);
        if (!dptr->data)
            return -ENOMEM;
        memset(dptr->data, 0, qset * sizeof(char *));
    }
    /* Allocate a quantum using virtual addresses */
    if (!dptr->data[s_pos]) {
        dptr->data[s_pos] = (void *)vmalloc(PAGE_SIZE << order);
        if (!dptr->data[s_pos])
            return -ENOMEM;
    }
    if (count > quantum - q_pos)
        count = quantum - q_pos; /* write only up to the end of this quantum */
    memcpy_fromfs(dptr->data[s_pos]+q_pos, buf, count);

    /* update the size */
    if (dev->size < f_pos + count)
        dev-> size = f_pos + count;
    filp->f_pos += count;
    return count;
}

/*
 * The ioctl() implementation
 */

int scullv_ioctl (struct inode *inode, struct file *filp,
                 unsigned int cmd, unsigned long arg)
{

    int err= 0, tmp, size = _IOC_SIZE(cmd);

    /* don't even decode wrong cmds: better returning  EINVAL than EFAULT */
    if (_IOC_TYPE(cmd) != SCULLV_IOC_MAGIC) return -EINVAL;
    if (_IOC_NR(cmd) > SCULLV_IOC_MAXNR) return -EINVAL;

    /*
     * the type is a bitmask, and VERIFY_WRITE catches R/W
     * transfers. Note that the type is user-oriented, while
     * verify_area is kernel-oriented, so the concept of "read" and
     * "write" is reversed
     */
    if (_IOC_TYPE(cmd) & _IOC_READ)
        err = verify_area(VERIFY_WRITE, (void *)arg, size);
    else if (_IOC_TYPE(cmd) & _IOC_WRITE)
        err =  verify_area(VERIFY_READ, (void *)arg, size);
    if (err) return err;

    switch(cmd) {

#ifdef SCULLV_DEBUG
      case SCULLV_IOCHARDRESET:
        /*
         * reset the counter to 1, to allow unloading in case of problems.
         * Use 1, not 0, because the invoking file is still to be closed.
         */
        mod_use_count_ = 1;
        /* don't break: fall through */
#endif

      case SCULLV_IOCRESET:
        scullv_order = SCULLV_ORDER;
        scullv_qset = SCULLV_QSET;
        break;
        
      case SCULLV_IOCSORDER: /* Set: arg points to the value */
        scullv_order = get_user((int *)arg);
        break;

      case SCULLV_IOCTORDER: /* Tell: arg is the value */
        scullv_order = arg;
        break;

      case SCULLV_IOCGORDER: /* Get: arg is pointer to result */
        put_user(scullv_order, (int *)arg);
        break;

      case SCULLV_IOCQORDER: /* Query: return it (it's positive) */
        return scullv_order;

      case SCULLV_IOCXORDER: /* eXchange: use arg as pointer */
        tmp = scullv_order;
        scullv_order = get_user((int *)arg);
        put_user(tmp, (int *)arg);
        break;

      case SCULLV_IOCHORDER: /* sHift: like Tell + Query */
        tmp = scullv_order;
        scullv_order = arg;
        return tmp;
        
      case SCULLV_IOCSQSET:
        scullv_qset = get_user((int *)arg);
        break;

      case SCULLV_IOCTQSET:
        scullv_qset = arg;
        break;

      case SCULLV_IOCGQSET:
        put_user(scullv_qset, (int *)arg);
        break;

      case SCULLV_IOCQQSET:
        return scullv_qset;

      case SCULLV_IOCXQSET:
        tmp = scullv_qset;
        scullv_qset = get_user((int *)arg);
        put_user(tmp, (int *)arg);
        break;

      case SCULLV_IOCHQSET:
        tmp = scullv_qset;
        scullv_order = arg;
        return tmp;

      default:  /* redundant, as cmd was checked against MAXNR */
        return -EINVAL;
    }
    return 0;

}

/*
 * The "extended" operations -- only seek
 */

int scullv_lseek (struct inode *inode, struct file *filp,
                 off_t off, int whence)
{
    ScullV_Dev *dev = filp->private_data;
    long newpos;

    switch(whence) {
      case 0: /* SEEK_SET */
        newpos = off;
        break;

      case 1: /* SEEK_CUR */
        newpos = filp->f_pos + off;
        break;

      case 2: /* SEEK_END */
        newpos = dev->size + off;
        break;

      default: /* can't happen */
        return -EINVAL;
    }
    if (newpos<0) return -EINVAL;
    filp->f_pos = newpos;
    return newpos;
}

/*
 * Mmap *is* available, but confined in a different file
 */
extern int scullv_mmap(struct inode *inode, struct file *filp,
                       struct vm_area_struct *vma);

/*
 * The different file operations
 */

struct file_operations scullv_fops = {
    scullv_lseek,
    scullv_read,
    scullv_write,
    NULL,          /* scullv_readdir */
    NULL,          /* scullv_select */
    scullv_ioctl,
    scullv_mmap,
    scullv_open,
    scullv_release,
    NULL,          /* scullv_fsync */
    NULL,          /* scullv_fasync */
                   /* nothing more, fill with NULLs */
};

int scullv_trim(ScullV_Dev *dev)
{
    ScullV_Dev *next, *dptr;
    int qset = dev->qset;   /* "dev" is not-null */
    int i;

    if (dev->vmas)
        return -EBUSY;  /* don't free: it's mem-mapped */

    for (dptr = dev; dptr; dptr = next) { /* all the list items */
        if (dptr->data) {

            /* Release the quantum-set */
            for (i = 0; i < qset; i++)
                if (dptr->data[i])
                    vfree(dptr->data[i]);
            kfree(dptr->data);
            dptr->data=NULL;
        }
        next=dptr->next;
        if (dptr != dev) kfree(dptr); /* all of them but the first */
    }
    dev->size = 0;
    dev->order = scullv_order;
    dev->qset = scullv_qset;
    dev->next = NULL;
    return 0;
}


/*
 * Finally, the module stuff
 */

int init_module(void)
{
    int result, i;

    /*
     * Register your major, and accept a dynamic number
     */
    result = register_chrdev(scullv_major, "scullv", &scullv_fops);
    if (result < 0) return result;
    if (scullv_major == 0) scullv_major = result; /* dynamic */

    /* 
     * allocate the devices -- we can't have them static, as the number
     * can be specified at load time
     */
    scullv_devices = kmalloc(scullv_devs * sizeof (ScullV_Dev), GFP_KERNEL);
    if (!scullv_devices) {
        result = -ENOMEM;
        goto fail_malloc;
    }
    memset(scullv_devices, 0, scullv_devs * sizeof (ScullV_Dev));
    for (i=0; i < scullv_devs; i++) {
        scullv_devices[i].order = scullv_order;
        scullv_devices[i].qset = scullv_qset;
    }

#ifdef SCULLV_USE_PROC /* only when available */
    /* this is the last line in init_module */
    proc_register_dynamic(&proc_root, &scullv_proc_entry);
#endif

    return 0; /* succeed */

  fail_malloc: unregister_chrdev(scullv_major, "scullv");
    return result;
}

void cleanup_module(void)
{
    int i;
    unregister_chrdev(scullv_major, "scullv");

#ifdef SCULLV_USE_PROC
    proc_unregister(&proc_root, scullv_proc_entry.low_ino);
#endif

    for (i=0; i<scullv_devs; i++)
        scullv_trim(scullv_devices+i);
    kfree(scullv_devices);
}




