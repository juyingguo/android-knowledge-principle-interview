/*
 * jit.c -- the just-in-time module
 *
 * Tested with 2.0 on the x86, Sparc
 */

/* BUGS: this module is not reentrant: only one file can be read at a time
 *       the module usage count is not used: you could remove the module
 *           while reading it, thus asking for troubles
 */
 
#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/module.h>

#define VERSION_CODE(vers,rel,seq) ( ((vers)<<16) | ((rel)<<8) | (seq) )

#if LINUX_VERSION_CODE < VERSION_CODE(1,99,4)
#  error "This module needs Linux 1.99.4 or newer"
#else

#include <linux/sched.h>
#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/proc_fs.h>
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */

/*
 * This module is a silly one: it only embeds short code fragments
 * that show how time delays can be handled in the kernel.
 */

int jit_delay = 1; /* the default delay in read() */

char jit_spoke[] = "This is a meaningless string, fiftysix characters long.\n";

#define LIMIT (PAGE_SIZE-128) /* don't print any more after this size */

static int jit_print(char *buf)
{
    int len = 0;
    while(len < LIMIT)
        len += sprintf(buf+len,"%s",jit_spoke);
    return len;
}

int jit_read_busy(char *buf, char **start, off_t offset,
                   int len, int unused)
{
    /* delay one second (or the chosen value), before printing */
    unsigned long j= jiffies + jit_delay * HZ;

    while (jiffies < j)
	/* nothing */;

    return jit_print(buf);
}

int jit_read_sched(char *buf, char **start, off_t offset,
                   int len, int unused)
{
    /* delay one second (or the chosen value), before printing */
    unsigned long j= jiffies + jit_delay * HZ;

    while (jiffies < j)
	schedule();

    return jit_print(buf);
}

int jit_read_queue(char *buf, char **start, off_t offset,
                   int len, int unused)
{
    /* delay one second (or the chosen value), before printing */
    unsigned long j= jiffies + jit_delay * HZ;
    
    struct wait_queue *wait = NULL;

    current->timeout = j;
    interruptible_sleep_on(&wait);

    return jit_print(buf);
}
int jit_read_self(char *buf, char **start, off_t offset,
                   int len, int unused)
{
    /* delay one second (or the chosen value), before printing */
    unsigned long j= jiffies + jit_delay * HZ;

    current->timeout = j;
    current->state = TASK_INTERRUPTIBLE;
    schedule();
    current->timeout = 0; /* reset the timeout */

    return jit_print(buf);
}

struct proc_dir_entry jit_proc_busy = {
        0,                 /* low_ino: the inode -- dynamic */
        7, "jitbusy",      /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &jit_read_busy,    /* function used to read data */
        /* nothing more */
    };

struct proc_dir_entry jit_proc_sched = {
        0,                 /* low_ino: the inode -- dynamic */
        8, "jitsched",     /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &jit_read_sched,   /* function used to read data */
        /* nothing more */
    };

struct proc_dir_entry jit_proc_queue = {
        0,                 /* low_ino: the inode -- dynamic */
        8, "jitqueue",     /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &jit_read_queue,    /* function used to read data */
        /* nothing more */
    };

struct proc_dir_entry jit_proc_self = {
        0,                 /* low_ino: the inode -- dynamic */
        7, "jitself",      /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &jit_read_self,    /* function used to read data */
        /* nothing more */
    };


/*
 * There is also a silly file returning the current time.
 */

int jit_read_current(char *buf, char **start, off_t offset,
                   int len, int unused)
{
    struct timeval tv1, tv2;
    unsigned long flags;

    do_gettimeofday(&tv1);
    save_flags(flags);
    cli();
    tv2 = xtime;
    restore_flags(flags);

    len=0;
    len += sprintf(buf,"gettime: %9i.%06i\nxtime:   %9i.%06i\njiffies: %li\n",
                   tv1.tv_sec, tv1.tv_usec,
                   tv2.tv_sec, tv2.tv_usec, jiffies);
    return len;
}

struct proc_dir_entry jit_proc_current = {
        0,                 /* low_ino: the inode -- dynamic */
        10, "currentime",  /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &jit_read_current, /* function used to read data */
        /* nothing more */
    };

int init_module(void)
{
    proc_register_dynamic(&proc_root, &jit_proc_busy);
    proc_register_dynamic(&proc_root, &jit_proc_sched);
    proc_register_dynamic(&proc_root, &jit_proc_queue);
    proc_register_dynamic(&proc_root, &jit_proc_self);
    proc_register_dynamic(&proc_root, &jit_proc_current);
#ifndef JIT_DEBUG
    register_symtab(NULL); /* hide symbols */
#endif
    return 0; /* succeed */
}

void cleanup_module(void)
{
    proc_unregister(&proc_root, jit_proc_busy.low_ino);
    proc_unregister(&proc_root, jit_proc_sched.low_ino);
    proc_unregister(&proc_root, jit_proc_queue.low_ino);
    proc_unregister(&proc_root, jit_proc_self.low_ino);
    proc_unregister(&proc_root, jit_proc_current.low_ino);
}

#endif /* version 1.99.4 or newer */
