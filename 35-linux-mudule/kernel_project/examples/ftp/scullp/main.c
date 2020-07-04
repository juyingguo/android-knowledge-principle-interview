/*
 * main.c -- the bare scull-page char module
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

#include "scullp.h"        /* local definitions */


/*
 * I don't use static symbols here, because register_symtab is called
 */

int scullp_major =   SCULLP_MAJOR;
int scullp_devs =    SCULLP_DEVS;    /* number of bare scullp devices */
int scullp_order =   SCULLP_ORDER;
int scullp_qset =    SCULLP_QSET;

ScullP_Dev *scullp_devices; /* allocated in init_module */

int scullp_trim(ScullP_Dev *dev);

#ifdef SCULLP_USE_PROC /* don't waste space if unused */
/*
 * The proc filesystem: function to read and entry
 */

int scullp_read_procmem(char *buf, char **start, off_t offset,
                   int len, int unused)
{
    int i, j, order, qset;
    ScullP_Dev *d;

    #define LIMIT (PAGE_SIZE-80) /* don't print any more after this size */
    len=0;
    for(i=0; i<scullp_devs; i++) {
        d=&scullp_devices[i];
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

struct proc_dir_entry scullp_proc_entry = {
        0,                 /* low_ino: the inode -- dynamic */
        9, "scullpmem",    /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &scullp_read_procmem,   /* function used to read data */
        /* nothing more */
    };
#endif /* SCULLP_USE_PROC */

/*
 * Open and close
 */

int scullp_open (struct inode *inode, struct file *filp)
{
    int num = MINOR(inode->i_rdev);
    ScullP_Dev *dev; /* device information */

    /*  check the device number */
    if (num >= scullp_devs) return -ENODEV;
    dev = &scullp_devices[num];

    /* now trim to 0 the length of the device if open was write-only */
    if ( (filp->f_flags & O_ACCMODE) == O_WRONLY)
        scullp_trim(dev);

    /* and use filp->private_data to point to the device data */
    filp->private_data = dev;

    MOD_INC_USE_COUNT;
    return 0;          /* success */
}

void scullp_release (struct inode *inode, struct file *filp)
{
    MOD_DEC_USE_COUNT;
}

/*
 * Follow the list 
 */
ScullP_Dev *scullp_follow(ScullP_Dev *dev, int n)
{
    while (n--) {
        if (!dev->next) {
            dev->next = kmalloc(sizeof(ScullP_Dev), GFP_KERNEL);
            memset(dev->next, 0, sizeof(ScullP_Dev));
        }
        dev = dev->next;
        continue;
    }
    return dev;
}

/*
 * Data management: read and write
 */

read_write_t scullp_read (struct inode *inode, struct file *filp,
                char *buf, count_t count)
{
    ScullP_Dev *dev = filp->private_data; /* the first listitem */
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
    dev = scullp_follow(dev, item);

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

read_write_t scullp_write (struct inode *inode, struct file *filp,
                const char *buf, count_t count)
{
    ScullP_Dev *dev = filp->private_data;
    ScullP_Dev *dptr;
    int quantum = PAGE_SIZE << dev->order;
    int qset = dev->qset;
    int itemsize = quantum * qset;
    unsigned long f_pos = (unsigned long)(filp->f_pos);
    int item, s_pos, q_pos, rest;

    /* find listitem, qset index and offset in the quantum */
    item = f_pos / itemsize;
    rest = f_pos % itemsize;
    s_pos = rest / quantum; q_pos = rest % quantum;

    /* follow the list up to the right position */
    dptr = scullp_follow(dev, item);
    if (!dptr->data) {
        dptr->data = kmalloc(qset * sizeof(void *), GFP_KERNEL);
        if (!dptr->data)
            return -ENOMEM;
        memset(dptr->data, 0, qset * sizeof(char *));
    }

#if LINUX_VERSION_CODE >= VERSION_CODE(2,0,0)
    /* Here's the allocation of a single quantum */
    if (!dptr->data[s_pos]) {
        dptr->data[s_pos] = (void *)__get_free_pages(GFP_KERNEL,
                                                     dptr->order,0);
        if (!dptr->data[s_pos])
            return -ENOMEM;
        memset(dptr->data[s_pos], 0, PAGE_SIZE << dptr->order);
#else
    /* The same, without order support */
    if (!dptr->data[s_pos]) {
        dptr->data[s_pos] = (void *)get_free_page(GFP_KERNEL);
        if (!dptr->data[s_pos])
            return -ENOMEM;
#endif
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

int scullp_ioctl (struct inode *inode, struct file *filp,
                 unsigned int cmd, unsigned long arg)
{

    int err= 0, tmp, size = _IOC_SIZE(cmd);
#if LINUX_VERSION_CODE < VERSION_CODE(2,0,0)
    int saveorder = scullp_order;
#endif

    /* don't even decode wrong cmds: better returning  EINVAL than EFAULT */
    if (_IOC_TYPE(cmd) != SCULLP_IOC_MAGIC) return -EINVAL;
    if (_IOC_NR(cmd) > SCULLP_IOC_MAXNR) return -EINVAL;

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

#ifdef SCULLP_DEBUG
      case SCULLP_IOCHARDRESET:
        /*
         * reset the counter to 1, to allow unloading in case of problems.
         * Use 1, not 0, because the invoking file is still to be closed.
         */
        mod_use_count_ = 1;
        /* don't break: fall through */
#endif

      case SCULLP_IOCRESET:
        scullp_order = SCULLP_ORDER;
        scullp_qset = SCULLP_QSET;
        break;
        
      case SCULLP_IOCSORDER: /* Set: arg points to the value */
        scullp_order = get_user((int *)arg);
        break;

      case SCULLP_IOCTORDER: /* Tell: arg is the value */
        scullp_order = arg;
        break;

      case SCULLP_IOCGORDER: /* Get: arg is pointer to result */
        put_user(scullp_order, (int *)arg);
        break;

      case SCULLP_IOCQORDER: /* Query: return it (it's positive) */
        return scullp_order;

      case SCULLP_IOCXORDER: /* eXchange: use arg as pointer */
        tmp = scullp_order;
        scullp_order = get_user((int *)arg);
        put_user(tmp, (int *)arg);
        break;

      case SCULLP_IOCHORDER: /* sHift: like Tell + Query */
        tmp = scullp_order;
        scullp_order = arg;
        return tmp;
        
      case SCULLP_IOCSQSET:
        scullp_qset = get_user((int *)arg);
        break;

      case SCULLP_IOCTQSET:
        scullp_qset = arg;
        break;

      case SCULLP_IOCGQSET:
        put_user(scullp_qset, (int *)arg);
        break;

      case SCULLP_IOCQQSET:
        return scullp_qset;

      case SCULLP_IOCXQSET:
        tmp = scullp_qset;
        scullp_qset = get_user((int *)arg);
        put_user(tmp, (int *)arg);
        break;

      case SCULLP_IOCHQSET:
        tmp = scullp_qset;
        scullp_order = arg;
        return tmp;

      default:  /* redundant, as cmd was checked against MAXNR */
        return -EINVAL;
    }

#if LINUX_VERSION_CODE < VERSION_CODE(2,0,0)
    if (scullp_order != saveorder) {
        scullp_order = saveorder;
        return -EINVAL; /* can't change the order */
    }
#endif
    return 0;

}

/*
 * The "extended" operations
 */

int scullp_lseek (struct inode *inode, struct file *filp,
                 off_t off, int whence)
{
    ScullP_Dev *dev = filp->private_data;
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
extern int scullp_mmap(struct inode *inode, struct file *filp,
                       struct vm_area_struct *vma);

/*
 * The fops
 */

struct file_operations scullp_fops = {
    scullp_lseek,
    scullp_read,
    scullp_write,
    NULL,          /* scullp_readdir */
    NULL,          /* scullp_select */
    scullp_ioctl,
    scullp_mmap,
    scullp_open,
    scullp_release,
    NULL,          /* scullp_fsync */
    NULL,          /* scullp_fasync */
                   /* nothing more, fill with NULLs */
};

int scullp_trim(ScullP_Dev *dev)
{
    ScullP_Dev *next, *dptr;
    int qset = dev->qset;   /* "dev" is not-null */
    int i;

    if (dev->vmas) /* don't trim: there are active mappings */
        return -EBUSY;

    for (dptr = dev; dptr; dptr = next) { /* all the list items */
        if (dptr->data) {
#if LINUX_VERSION_CODE >= VERSION_CODE(2,0,0)           

            /* This code frees a whole quantum-set */
            for (i = 0; i < qset; i++)
                if (dptr->data[i])
                    free_pages((unsigned long)(dptr->data[i]),
                               dptr->order);
#else
            /* This does the same but without order support */
            for (i = 0; i < qset; i++)
                if (dptr->data[i])
                    free_page((unsigned long)(dptr->data[i]));
#endif
            kfree(dptr->data);
            dptr->data=NULL;
        }
        next=dptr->next;
        if (dptr != dev) kfree(dptr); /* all of them but the first */
    }
    dev->size = 0;
    dev->qset = scullp_qset;
    dev->order = scullp_order;
    dev->next = NULL;
    return 0;
}




/*
 * Finally, the module stuff
 */

int init_module(void)
{
    int result, i;

#if LINUX_VERSION_CODE < VERSION_CODE(2,0,0)           
    if (scullp_order) {
        printk(KERN_ERR "scullp: can't change the order\n");
        return -EINVAL;
    }
#endif
        
    /*
     * Register your major, and accept a dynamic number
     */
    result = register_chrdev(scullp_major, "scullp", &scullp_fops);
    if (result < 0) return result;
    if (scullp_major == 0) scullp_major = result; /* dynamic */

    /* 
     * allocate the devices -- we can't have them static, as the number
     * can be specified at load time
     */
    scullp_devices = kmalloc(scullp_devs * sizeof (ScullP_Dev), GFP_KERNEL);
    if (!scullp_devices) {
        result = -ENOMEM;
        goto fail_malloc;
    }
    memset(scullp_devices, 0, scullp_devs * sizeof (ScullP_Dev));
    for (i=0; i < scullp_devs; i++) {
        scullp_devices[i].order = scullp_order;
        scullp_devices[i].qset = scullp_qset;
    }

#ifdef SCULLP_USE_PROC /* only when available */
    /* this is the last line in init_module */
    proc_register_dynamic(&proc_root, &scullp_proc_entry);
#endif

    return 0; /* succeed */

  fail_malloc: unregister_chrdev(scullp_major, "scullp");
    return result;
}

void cleanup_module(void)
{
    int i;
    unregister_chrdev(scullp_major, "scullp");

#ifdef SCULLP_USE_PROC
    proc_unregister(&proc_root, scullp_proc_entry.low_ino);
#endif

    for (i=0; i<scullp_devs; i++)
        scullp_trim(scullp_devices+i);
    kfree(scullp_devices);
}




