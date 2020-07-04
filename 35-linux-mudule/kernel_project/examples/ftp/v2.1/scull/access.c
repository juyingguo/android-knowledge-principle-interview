/*
 * access.c -- the files with access control on open (v2.1)
 *
 */

 
#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#define __NO_VERSION__
#include <linux/module.h> /* get MOD_DEC_USE_COUNT, not the version string */
#include <linux/version.h> /* need it for conditionals in scull.h */

#include <linux/kernel.h> /* printk() */
#include <linux/malloc.h> /* kmalloc() */
#include <linux/fs.h>     /* everything... */
#include <linux/proc_fs.h>
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/fcntl.h>
#include <linux/tty.h>    /* current->tty */

#include "scull.h"        /* local definitions */

/*
 * These devices fall back on the main scull operations. They only
 * differ in the implementation of open() and close()
 */

/************************************************************************
 *
 * The first device is the single-open one,
 *  it has an hw structure and an open count
 */

 Scull_Dev scull_s_device;
 int scull_s_count = 0;

int scull_s_open (struct inode *inode, struct file *filp)
{
    Scull_Dev *dev = &scull_s_device; /* device information */
    int num = NUM(inode->i_rdev);

    if (num > 0) return -ENODEV; /* 1 device only */
    if (scull_s_count) return -EBUSY; /* already open */
    scull_s_count++;

    /* then, everything else is copied from the bare scull device */

    if ( (filp->f_flags & O_ACCMODE) == O_WRONLY)
        scull_trim(dev);
    filp->private_data = dev;
    MOD_INC_USE_COUNT;
    return 0;          /* success */
}

release_t scull_s_release (struct inode *inode, struct file *filp)
{
    scull_s_count--; /* release the device */
    MOD_DEC_USE_COUNT;
    release_return(0);
}

/*
 * The other operations for the single-open device come from the bare device
 */
struct file_operations scull_sngl_fops = {
    scull_lseek,
    scull_read,
    scull_write,
    NULL,          /* scull_readdir */
    NULL,          /* scull_select */
    scull_ioctl,
    NULL,          /* scull_mmap */
    scull_s_open,
    scull_s_release,
    NULL,          /* scull_fsync */
    NULL,          /* scull_fasync */
                   /* nothing more, fill with NULLs */
};


/************************************************************************
 *
 * Next, the "uid" device. It can be opened multiple times by the
 * same user, but access is denied to other users if the device is open
 */

Scull_Dev scull_u_device;
int scull_u_count = 0;
uid_t scull_u_owner = 0;

int scull_u_open (struct inode *inode, struct file *filp)
{
    Scull_Dev *dev = &scull_u_device; /* device information */
    int num = NUM(inode->i_rdev);

    if (num > 0) return -ENODEV; /* 1 device only */
    if (scull_u_count && 
        (scull_u_owner != current->uid) &&  /* allow user */
        (scull_u_owner != current->euid) && /* allow whoever did su */
        !suser()) /* still allow root */
         return -EBUSY;   /* -EPERM would confuse the user */

    if (scull_u_count == 0)
        scull_u_owner = current->uid; /* grab it */

    scull_u_count++;

    /* then, everything else is copied from the bare scull device */

    if ( (filp->f_flags & O_ACCMODE) == O_WRONLY)
        scull_trim(dev);
    filp->private_data = dev;
    MOD_INC_USE_COUNT;
    return 0;          /* success */
}

release_t scull_u_release (struct inode *inode, struct file *filp)
{
    scull_u_count--; /* nothing else */
    MOD_DEC_USE_COUNT;
    release_return(0);
}

/*
 * The other operations for the device come from the bare device
 */
struct file_operations scull_user_fops = {
    scull_lseek,
    scull_read,
    scull_write,
    NULL,          /* scull_readdir */
    NULL,          /* scull_select */
    scull_ioctl,
    NULL,          /* scull_mmap */
    scull_u_open,
    scull_u_release,
    NULL,          /* scull_fsync */
    NULL,          /* scull_fasync */
                   /* nothing more, fill with NULLs */
};


/************************************************************************
 *
 * Next, the device with blocking-open based on uid
 */

Scull_Dev scull_w_device;
int scull_w_count = 0;
uid_t scull_w_owner = 0;
struct wait_queue *scull_w_wait;

int scull_w_open (struct inode *inode, struct file *filp)
{
    Scull_Dev *dev = &scull_w_device; /* device information */
    int num = NUM(inode->i_rdev);

    if (num > 0) return -ENODEV; /* 1 device only */
    while (scull_w_count && 
      (scull_w_owner != current->uid) &&  /* allow user */
      (scull_w_owner != current->euid) && /* allow whoever did su */
      !suser()) {
        if (filp->f_flags & O_NONBLOCK) return -EAGAIN; 
        interruptible_sleep_on(&scull_w_wait);
        if (current->signal & ~current->blocked) /* a signal arrived */
          return -ERESTARTSYS; /* tell the fs layer to handle it */
        /* else, loop */
    }
    if (scull_w_count == 0)
        scull_w_owner = current->uid; /* grab it */
    scull_w_count++;

    /* then, everything else is copied from the bare scull device */

    if ( (filp->f_flags & O_ACCMODE) == O_WRONLY)
        scull_trim(dev);
    filp->private_data = dev;
    MOD_INC_USE_COUNT;
    return 0;          /* success */
}

release_t scull_w_release (struct inode *inode, struct file *filp)
{
    scull_w_count--;
    if (scull_w_count == 0)
        wake_up_interruptible(&scull_w_wait); /* awake other uid's */
    MOD_DEC_USE_COUNT;
    release_return(0);
}

/*
 * The other operations for the device come from the bare device
 */
struct file_operations scull_wusr_fops = {
    scull_lseek,
    scull_read,
    scull_write,
    NULL,          /* scull_readdir */
    NULL,          /* scull_select */
    scull_ioctl,
    NULL,          /* scull_mmap */
    scull_w_open,
    scull_w_release,
    NULL,          /* scull_fsync */
    NULL,          /* scull_fasync */
                   /* nothing more, fill with NULLs */
};

/************************************************************************
 *
 * Finally the `cloned' private device. This is trickier because it
 * involves list management, and dynamic allocation.
 */

struct scull_listitem {
    Scull_Dev device;
    int key;
    struct scull_listitem *next;
};

struct scull_listitem *scull_c_head;

int scull_c_open (struct inode *inode, struct file *filp)
{
    int key;
    int num = NUM(inode->i_rdev);
    struct scull_listitem *lptr, *prev;

    if (num > 0) return -ENODEV; /* 1 device only */

    if (!current->tty) {
        PDEBUG("Process \"%s\" has no ctl tty\n",current->comm);
        return -EINVAL;
    }
    key = MINOR(current->tty->device);

    /* look for a device in the linked list; if missing create it */
    prev = NULL;
    for (lptr = scull_c_head; lptr && (lptr->key != key); lptr = lptr->next)
        prev=lptr;
    if (!lptr) { /* not found */
        lptr = kmalloc(sizeof(struct scull_listitem), GFP_KERNEL);
        if (!lptr)
            return -ENOMEM;
        memset(lptr, 0, sizeof(struct scull_listitem));
        lptr->key = key;
        scull_trim(&(lptr->device)); /* initialize it */
        if (prev)
            prev->next = lptr;
        else
            scull_c_head = lptr; /* the first one */
    }

    /* then, everything else is copied from the bare scull device */

    if ( (filp->f_flags & O_ACCMODE) == O_WRONLY)
        scull_trim(&(lptr->device));
    filp->private_data = &(lptr->device);
    MOD_INC_USE_COUNT;
    return 0;          /* success */
}

release_t scull_c_release (struct inode *inode, struct file *filp)
{
    /*
     * Nothing to do, because the device is persistent.
     * A `real' cloned device should be freed on last close
     */
    MOD_DEC_USE_COUNT;
    release_return(0);
}

/*
 * The other operations for the device come from the bare device
 */
struct file_operations scull_priv_fops = {
    scull_lseek,
    scull_read,
    scull_write,
    NULL,          /* scull_readdir */
    NULL,          /* scull_select */
    scull_ioctl,
    NULL,          /* scull_mmap */
    scull_c_open,
    scull_c_release,
    NULL,          /* scull_fsync */
    NULL,          /* scull_fasync */
                   /* nothing more, fill with NULLs */
};

/************************************************************************
 *
 * And the init and cleanup functions come last
 */

int scull_access_init(void)
{
    /* assign quantum and quantumset */
    scull_s_device.quantum = scull_quantum;
    scull_s_device.qset    = scull_qset;
    scull_u_device.quantum = scull_quantum;
    scull_u_device.qset    = scull_qset;
    scull_w_device.quantum = scull_quantum;
    scull_w_device.qset    = scull_qset;

    return 0;
}

void scull_access_cleanup(void) /* called by cleanup_module */
{
    struct scull_listitem *lptr, *prev;

    scull_trim(&scull_s_device); /* disallocate it */
    scull_trim(&scull_u_device); /* disallocate it */
    scull_trim(&scull_w_device); /* disallocate it */

    /* all the cloned devices */
    prev=NULL;
    for (lptr = scull_c_head; lptr; lptr = lptr->next) {
        scull_trim(&(lptr->device));
        if (prev) kfree(prev);
        prev=lptr;
    }
    if (prev) kfree(prev);
    scull_c_head = NULL; /* overkill: we're unloading anyways */

    return;
}




