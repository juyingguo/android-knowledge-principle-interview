/*
 * pipe.c -- fifo driver for scull (v2.1)
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

#include <asm/segment.h>  /* memcpy to/from fs */

#include "scull.h"        /* local definitions */

typedef struct Scull_Pipe {
    struct wait_queue *inq, *outq;  /* read and write queues */
    char *buffer, *end;             /* begin of buf, end of buf */
    int buffersize;                 /* used in pointer arithmetic */
    char *rp, *wp;                  /* where to read, where to write */
    int nreaders, nwriters;         /* number of openings for r/w */
    struct fasync_struct *async_queue; /* asynchronous readers */
} Scull_Pipe;


/*
 * I don't use static symbols here, because register_symtab is called
 */

int scull_p_nr_devs =    SCULL_P_NR_DEVS;  /* number of pipe devices */
int scull_p_buffer =  SCULL_P_BUFFER; /* buffer size */

Scull_Pipe *scull_p_devices;

/*
 * Open and close
 */

int scull_p_open (struct inode *inode, struct file *filp)
{
    Scull_Pipe *dev;
    int num = NUM(inode->i_rdev);

    if (num >= scull_p_nr_devs) return -ENODEV;
    dev = &scull_p_devices[num];
    if (!dev->buffer) { /* allocate the buffer */
        dev->buffer = kmalloc(scull_p_buffer, GFP_KERNEL);
        if (!dev->buffer)
            return -ENOMEM;
    }
    dev->buffersize = scull_p_buffer;
    dev->end = dev->buffer + dev->buffersize;
    dev->rp = dev->wp = dev->buffer; /* rd and wr from the beginning */

    /* use f_mode,not  f_flags: it's cleaner (fs/open.c tells why) */
    if (filp->f_mode & FMODE_READ)
        dev->nreaders++;
    if (filp->f_mode & FMODE_WRITE)
        dev->nwriters++;

    filp->private_data = dev;
    MOD_INC_USE_COUNT;
    return 0;
}

release_t scull_p_release (struct inode *inode, struct file *filp)
{
    Scull_Pipe *dev = filp->private_data;
    int scull_p_fasync (struct inode *inode, struct file *filp, int mode);

    /* remove this filp from the asynchronously notified filp's */
    scull_p_fasync(inode, filp, 0);
    if (filp->f_mode & FMODE_READ)
        dev->nreaders--;
    if (filp->f_mode & FMODE_WRITE)
        dev->nwriters--;
    if (dev->nreaders + dev->nwriters == 0) {
        kfree(dev->buffer);
        dev->buffer = NULL; /* the other fields are not checked on open */
    }
    MOD_DEC_USE_COUNT;
    release_return(0);
}

/*
 * Data management: read and write
 */

read_write_t scull_p_read (struct inode *inode, struct file *filp,
                char *buf, count_t count)
{
    Scull_Pipe *dev = filp->private_data;

    while (dev->rp == dev->wp) { /* nothing to read */
        if (filp->f_flags & O_NONBLOCK)
            return -EAGAIN;
        PDEBUG("\"%s\" reading: going to sleep\n",current->comm);
        interruptible_sleep_on(&dev->inq);
        if (current->signal & ~current->blocked) /* a signal arrived */
          return -ERESTARTSYS; /* tell the fs layer to handle it */
        /* otherwise loop */
    }
    /* ok, data is there, return something */
    if (dev->wp > dev->rp)
        count = min(count, dev->wp - dev->rp);
    else /* the write pointer has wrapped, return data up to dev->end */
        count = min(count, dev->end - dev->rp);
    copy_to_user(buf, dev->rp, count);
    dev->rp += count;
    if (dev->rp == dev->end)
        dev->rp = dev->buffer; /* wrapped */

    /* finally, awake any writers and return */
    wake_up_interruptible(&dev->outq);
    PDEBUG("\"%s\" did read %li bytes\n",current->comm, (long)count);
    return count;
}

read_write_t scull_p_write (struct inode *inode, struct file *filp,
                const char *buf, count_t count)
{
    Scull_Pipe *dev = filp->private_data;
    /* left is the free space in the buffer, but it must be positive */
    int left = (dev->rp + dev->buffersize - dev->wp) % dev->buffersize;

    PDEBUG("write: left is %i\n",left);
    while (left==1) { /* empty */
        if (filp->f_flags & O_NONBLOCK)
            return -EAGAIN;
        PDEBUG("\"%s\" writing: going to sleep\n",current->comm);
        interruptible_sleep_on(&dev->outq);
        if (current->signal & ~current->blocked) /* a signal arrived */
          return -ERESTARTSYS; /* tell the fs layer to handle it */
        /* otherwise loop, but recalculate free space */
        left = (dev->rp + dev->buffersize - dev->wp) % dev->buffersize;
    }
    /* ok, space is there, accept something */
    if (dev->wp >= dev->rp) {
        count = min(count, dev->end - dev->wp); /* up to end-of-buffer */
        if (count == left) /* leave a hole, even if at e-o-b */
            count--;
    }
    else /* the write pointer has wrapped, fill up to rp-1 */
        count = min(count, dev->rp - dev->wp - 1);
    PDEBUG("Going to accept %li bytes to %p from %p\n",
           (long)count, dev->wp, buf);
    copy_from_user(dev->wp, buf, count);
    dev->wp += count;
    if (dev->wp == dev->end)
        dev ->wp = dev->buffer; /* wrapped */

    /* finally, awake any reader */
    wake_up_interruptible(&dev->inq);  /* blocked in read() and select() */
    if (dev->async_queue)
        kill_fasync (dev->async_queue, SIGIO); /* asynchronous readers */
    PDEBUG("\"%s\" did write %li bytes\n",current->comm, (long)count);
    return count;
}

#ifdef __USE_OLD_SELECT__
int scull_p_poll (struct inode *inode, struct file *filp,
                  int mode, select_table *table)
{
    Scull_Pipe *dev = filp->private_data;

    if (mode == SEL_IN) {
        if (dev->rp != dev->wp) return 1; /* readable */
        PDEBUG("Waiting to read\n");
        select_wait(&dev->inq, table); /* wait for data */
        return 0;
    }
    if (mode == SEL_OUT) {
        /*
         * the buffer is full if "wp" is right behind "rp",
         * and the buffer is circular. "left" can't drop
         * to 0, as this would be taken as empty buffer
         */
        int left = (dev->rp + dev->buffersize - dev->wp) % dev->buffersize;
        if (left>1) return 1; /* writable */
        PDEBUG("Waiting to write\n");
        select_wait(&dev->outq, table); /* wait for free space */
        return 0;
    }
    return 0; /* never exception-able */
}

#else /* the new poll interface */

unsigned int scull_p_poll (struct file *filp, poll_table *wait)
{
    Scull_Pipe *dev = filp->private_data;
    unsigned int mask = 0;

    /* how many bytes left there to be read? */
    int left = (dev->rp + dev->buffersize - dev->wp) % dev->buffersize;

    poll_wait(&dev->inq,  wait);
    poll_wait(&dev->outq, wait);
    if (dev->rp != dev->wp) mask |= POLLIN | POLLRDNORM;  /* readable */
    if (left)               mask |= POLLOUT | POLLWRNORM; /* writable */

    return mask;
}

#endif


int scull_p_fasync (struct inode *inode, struct file *filp, int mode)
{
    Scull_Pipe *dev = filp->private_data;

    return fasync_helper(inode, filp, mode, &dev->async_queue);
}

lseek_t scull_p_lseek (struct inode *inode, struct file *filp,
                 lseek_off_t off, int whence)
{
    return -ESPIPE; /* unseekable */
}

#ifdef SCULL_USE_PROC
int scull_read_p_mem(char *buf, char **start, off_t offset,
                   int len, int unused)
{
    int i;
    Scull_Pipe *p;

    #define LIMIT (PAGE_SIZE-200) /* don't print any more after this size */
    len = sprintf(buf, "Default buffersize is %i\n", scull_p_buffer);
    for(i = 0; i<scull_p_nr_devs; i++) {
        if (len > LIMIT) break;
        p = &scull_p_devices[i];
        len += sprintf(buf+len, "\nDevice %i: %p\n", i, p);
        len += sprintf(buf+len, "   Queues: %p %p\n", p->inq, p->outq);
        len += sprintf(buf+len, "   Buffer: %p to %p (%i bytes)\n",
                       p->buffer, p->end, p->buffersize);
        len += sprintf(buf+len, "   rp %p   wp %p\n", p->rp, p->wp);
        len += sprintf(buf+len, "   readers %i   writers %i\n",
                       p->nreaders, p->nwriters);
    }
    return len;
}

struct proc_dir_entry scull_proc_p_entry = {
        0,                 /* low_ino: the inode -- dynamic */
        9, "scullpipe",     /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &scull_read_p_mem,   /* function used to read data */
        /* nothing more */
    };

#endif


/*
 * The file operations for the pipe device
 * (some are overlayed with bare scull)
 */
struct file_operations scull_pipe_fops = {
    scull_p_lseek,
    scull_p_read,
    scull_p_write,
    NULL,          /* scull_p_readdir */
    scull_p_poll,
    scull_ioctl,
    NULL,          /* scull_p_mmap */
    scull_p_open,
    scull_p_release,
    NULL,          /* scull_p_fsync */
    scull_p_fasync,
                   /* nothing more, fill with NULLs */
};



int scull_p_init(void)
{
    scull_p_devices = kmalloc(scull_p_nr_devs * sizeof(Scull_Pipe),
                              GFP_KERNEL);
    if (scull_p_devices == NULL)
        return -ENOMEM;
    memset(scull_p_devices, 0, scull_p_nr_devs * sizeof(Scull_Pipe));
#ifdef SCULL_USE_PROC
    proc_register_dynamic(&proc_root, &scull_proc_p_entry);
#endif
    return 0;
}

void scull_p_cleanup(void) /* called by cleanup_module */
{
    int i;
    for (i=0; i < scull_p_nr_devs; i++) {
        if (scull_p_devices[i].buffer)
            kfree(scull_p_devices[i].buffer);
    }
    kfree(scull_p_devices);
#ifdef SCULL_USE_PROC
    proc_unregister(&proc_root, scull_proc_p_entry.low_ino);
#endif
    return;
}




