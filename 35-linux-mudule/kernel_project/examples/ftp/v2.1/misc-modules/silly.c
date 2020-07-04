/*
 * silly.c -- Simple Tool for Unloading and Printing ISA Data (v2.1)
 *
 * Tested with 2.0 on the x86?
 * 
 * This module won't work on the sparc, where there's no concept of I/O space
 *
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#ifdef __sparc__
#  error "This module can't run on the Sparc platform"
#else

#define __NO_VERSION__ /* don't define kernel_verion in module.h */
#include <linux/module.h>
#include <linux/version.h>

char kernel_version [] = UTS_RELEASE;

#include <linux/sched.h>
#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/errno.h>  /* error codes */
#include <linux/tqueue.h>
#include <linux/malloc.h>
#include <linux/mm.h>
#include <linux/ioport.h>

#include <asm/io.h>
#include <asm/segment.h>  /* memcpy to/from fs */

#include "sysdep-2.1.h"

int silly_major = 0;

static int lines=25, columns=80; /* can be changed at load time */

/*
 * The devices access the 640k-1M memory.
 * minor 0 uses readb/writeb
 * minor 1 uses readw/writew
 * minor 2 uses readl/writel
 * minor 3 uses memcpy_fromio()/memcpy_toio()
 * minor 4 uses readl/writel over VGA mem (0xb8000-0xc0000)
 * minor 5 only drops letters in the VGA buffer
 */

static int silly_joke_write(int count);

int silly_open (struct inode *inode, struct file *filp)
{
    MOD_INC_USE_COUNT;
    return 0;
}

release_t silly_release (struct inode *inode, struct file *filp)
{
    MOD_DEC_USE_COUNT;
    release_return(0);
}

enum silly_modes {M_8=0, M_16, M_32, M_memcpy, M_vga, M_joke};

read_write_t silly_read (struct inode *inode, struct file *filp,
                char *buf, count_t count)
{
    int retval;
    int mode = MINOR(inode->i_rdev);
    unsigned long add = 0xA0000 + filp->f_pos;
    unsigned char *kbuf, *ptr;


    if (mode == M_joke) return 0;  /* no read on /dev/silliest */

    if (mode == M_vga) {
        add = 0xB8000 + filp->f_pos; /* range: 0xB8000-0xC0000 */
        if (add + count > 0xC0000)
            count = 0xC0000 - add;
        mode = M_32; /* and fall back to normal xfer */
    }
    else 
        if (add + count > 0x100000) /* range: 0xA0000-0x100000 */
            count = 0x100000 - add;

    /*
     * too big an f_pos (caused by a malicious lseek())
     * would result in a negative count
     */
    if (count < 0) return 0;

    kbuf = kmalloc(count, GFP_KERNEL);
    if (!kbuf) return -ENOMEM;
    ptr=kbuf;
    retval=count;

    /*
     * kbuf is aligned, but the reads might not. In order not to
     * drive me mad with unaligned leading and trailing bytes,
     * I downgrade the `mode' if unaligned xfers are requested.
     */

    if (mode==M_32 && ((add | count) & 3))
        mode = M_16;
    if (mode==M_16 && ((add | count) & 1))
        mode = M_8;

    switch(mode) {
      case M_32: 
        while (count >= 4) {
            *(u32 *)ptr = readl(add);
            add+=4; count-=4; ptr+=4;
        }
        break;
            
      case M_16: 
        while (count >= 2) {
            *(u16 *)ptr = readw(add);
            add+=2; count-=2; ptr+=2;
        }
        break;
            
      case M_8: 
        while (count) {
            *ptr = readb(add);
            add++; count--; ptr++;
        }
        break;

      case M_memcpy:
        memcpy_fromio(ptr, add, count);
        break;

      default:
        return -EINVAL;
    }
    if (retval > 0)
        copy_to_user(buf, kbuf, retval);
    kfree(kbuf);
    filp->f_pos += retval;
    return retval;
}

read_write_t silly_write (struct inode *inode, struct file *filp,
                const char *buf, count_t count)

{
    int retval;
    int mode = MINOR(inode->i_rdev);
    unsigned long add = 0xA0000 + filp->f_pos;
    unsigned char *kbuf, *ptr;

    /*
     * Writing is dangerous.
     * Allow root-only, independently of device permissions
     */
    if (!suser()) return -EPERM;

    if (mode == M_joke)
        return silly_joke_write(count);

    if (mode == M_vga) {
        add = 0xB8000 + filp->f_pos; /* range: 0xB8000-0xC0000 */
        if (add + count > 0xC0000)
            count = 0xC0000 - add;
        mode = M_32; /* and fall back to normal xfer */
    }
    else 
        if (add + count > 0x100000) /* range: 0xA0000-0x100000 */
            count = 0x100000 - add;

    /*
     * too big an f_pos (caused by a malicious lseek())
     * results in a negative count
     */
    if (count < 0) return 0;

    kbuf = kmalloc(count, GFP_KERNEL);
    if (!kbuf) return -ENOMEM;
    ptr=kbuf;
    retval=count;

    /*
     * kbuf is aligned, but the writes might not. In order not to
     * drive me mad with unaligned leading and trailing bytes,
     * I downgrade the `mode' if unaligned xfers are requested.
     */

    if (mode==M_32 && ((add | count) & 3))
        mode = M_16;
    if (mode==M_16 && ((add | count) & 1))
        mode = M_8;

    copy_from_user(kbuf, buf, count);
    ptr=kbuf;

    switch(mode) {
      case M_32: 
        while (count >= 4) {
            writel(*(u32 *)ptr, add);
            add+=4; count-=4; ptr+=4;
        }
        break;
            
      case M_16: 
        while (count >= 2) {
            writel(*(u16 *)ptr, add);
            add+=2; count-=2; ptr+=2;
        }
        break;
            
      case M_8: 
        while (count) {
            writeb(*ptr, add);
            add++; count--; ptr++;
        }
        break;

      case M_memcpy:
        memcpy_toio(add, ptr, count);
        break;

      default:
        return -EINVAL;
    }
    filp->f_pos += retval;
    return retval;
}


#ifdef __USE_OLD_SELECT__
int silly_poll (struct inode *inode, struct file *filp,
                  int mode, select_table *table)
{
    return mode==SEL_EX ? 0 : 1; /* readable, writable, not-exceptionable */
}
#else
unsigned int silly_poll (struct file *filp, poll_table *wait)
{
    return (POLLIN | POLLHUP);
}
#endif

/*
 * Dropping letters: use the timer queue to drop 10 rows per second.
 * Put the writing process to sleep, and don't manage more than 1 writer.
 *
 * Note that this isn't meant to show how to access the text buffer:
 * it must *not* be accessed this way. Look at selection.c for information
 * about the text buffer.
 */

struct wait_queue *jokeq;

struct tq_struct silly_task;

void silly_timerfn(void *ptr)
{
    unsigned long place = (unsigned long)ptr;
    char *ch, *ch2;
    static int time;

    ch = (char *)(0xb8000 + place*2);  /* two bytes every char-cell */
    ch2 = ch + columns * 2;
    if (place >= lines*columns || readb(ch) == ' ' || readb(ch2) != ' ') {
        /* printk("not good\n"); */
        wake_up_interruptible(&jokeq);
        return;
    }

    /* don't do it everytime, only ten times per second */
    if (time++ >= HZ/10) {
        time = 0;
        /* ("in queue: place %4i (%i,%i) -- %x %x\n", place, place%columns,
               place/columns, (int)ch, (int)ch2); */
        place += columns;
        writeb(readb(ch),ch2); writeb(' ',ch); /* down one */
        silly_task.data = (void *)place;
    }
    queue_task(&silly_task, &tq_timer);
    return;
}    

static int silly_joke_write(int count)
{
    int i, j;
    unsigned long place;
    char *ch, *ch2;
    
    for (i=0; i<count; i++) {
        /* choose a place with any algorithm */
        place = (unsigned int)(jiffies * 443) % (lines * columns);

        for (j=0; j<50; j++) { /* try 50 times */
            ch = (char *)(0xb8000 + place*2);
            ch2 = ch + 2*columns;
            if (readb(ch) == ' ' || readb(ch2) != ' ') {
                place *= 331; place %= (lines * columns);
                continue;
            }
            break;
        }
        silly_task.routine = silly_timerfn;
        silly_task.data = (void *)place;
        queue_task(&silly_task, &tq_timer);

        interruptible_sleep_on(&jokeq);
        if (current->signal & ~current->blocked)
            return -ERESTARTSYS;
    }
    return i;
}

/*
 * Done, the rest is normal
 */

struct file_operations silly_fops = {
    NULL,          /* silly_lseek */
    silly_read,
    silly_write,
    NULL,          /* silly_readdir */
    silly_poll,
    NULL,          /* silly_ioctl */
    NULL,          /* silly_mmap */
    silly_open,
    silly_release,
    NULL,          /* silly_fsync */
    NULL,          /* silly_fasync */
                   /* nothing more, fill with NULLs */
};

int init_module(void)
{
    int result = register_chrdev(silly_major, "silly", &silly_fops);
    if (result < 0) {
        printk(KERN_INFO "silly: can't get major number\n");
        return result;
    }
    if (silly_major == 0) silly_major = result; /* dynamic */
    return 0;
}

void cleanup_module(void)
{
    unregister_chrdev(silly_major, "silly");
}


#endif /* __386__ */
