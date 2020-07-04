/*
 * sleepy.c -- the writers awake the readers (v2.1)
 *
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

#include <linux/sched.h>  /* current and everything */
#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/types.h>  /* size_t */
#include <asm/segment.h>

#include "sysdep-2.1.h"

int sleepy_major=0;

struct wait_queue *wq = NULL; /* must be zeroed at the beginning */

read_write_t sleepy_read (struct inode *inode, struct file *filp,
                char *buf, count_t count)
{
    printk(KERN_DEBUG "process %i (%s) going to sleep\n",
           current->pid, current->comm);
    interruptible_sleep_on(&wq);
    printk(KERN_DEBUG "awoken %i (%s)\n", current->pid, current->comm);
    return 0; /* EOF */
}

read_write_t sleepy_write (struct inode *inode, struct file *filp,
                const char *buf, count_t count)
{
    printk(KERN_DEBUG "process %i (%s) awakening the readers...\n",
           current->pid, current->comm);
    wake_up_interruptible(&wq);
    return count; /* succeed, to avoid retrial */
}


struct file_operations sleepy_fops = {
    NULL,          /* lseek */
    sleepy_read,
    sleepy_write,
                   /* nothing more, fill with NULLs */
};


int init_module(void)
{
    int result;

    /*
     * Register your major, and accept a dynamic number
     */
    result = register_chrdev(sleepy_major, "sleepy", &sleepy_fops);
    if (result < 0) return result;
    if (sleepy_major == 0) sleepy_major = result; /* dynamic */

    return 0;
}

void cleanup_module(void)
{
    unregister_chrdev(sleepy_major, "sleepy");
}



