/*
 * short.c -- Simple Hardware Operations and Raw Tests
 * short.c -- also a brief example of interrupt handling ("short int")
 *
 * untested (by now) the hardware r/w
 *
 * Tested with 2.0.18 (intel & alpha -- but no irq available for me)
 * This module won't work on the sparc, where there's no concept of I/O space
 * 
 *********/

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#ifdef __sparc__
#  error "This module can't compile on the Sparc platform"
#else

#include <linux/module.h>

#include <linux/sched.h>
#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/errno.h>  /* error codes */
#include <linux/malloc.h>
#include <linux/mm.h>
#include <linux/ioport.h>
#include <linux/interrupt.h>
#include <linux/tqueue.h>

#include <asm/io.h>
#include <asm/segment.h>

#include "sysdep-2.1.h"

int short_major = 0;
#ifdef __alpha__
int short_base = 0x3bc; /* Hmm.... FIXME */
#else
int short_base = 0x378; /* intel: default to lp0 */
#endif
int short_irq = -1;
unsigned long short_buffer = 0;
unsigned long volatile short_head;
volatile unsigned long short_tail;
struct wait_queue *short_queue;

static int probe = 0; /* select at load time how to probe irq line */
static int bh = 0; /* select at load time whether a bottom-half is used */
static int share = 0; /* select at load time whether install a shared irq */

/*
 * The devices with low minor numbers write/read burst of data to/from
 * specific I/O ports (by default the parallel ones).
 * 
 * The device with 128 as minor number returns ascii strings telling
 * when interrupts have been received. Writing to the device toggles
 * 00/FF on the parallel data lines. If there is a loopback wire, this
 * generates interrupts.  
 */

int short_open (struct inode *inode, struct file *filp)
{
    extern struct file_operations short_i_fops;
    MOD_INC_USE_COUNT;
    if (MINOR(inode->i_rdev) & 0x80) {
        filp->f_op = &short_i_fops; /* the interrupt-driven node */
    }
    return 0;
}

release_t short_release (struct inode *inode, struct file *filp)
{
    MOD_DEC_USE_COUNT;
    release_return(0);
}


/* first, the port-oriented device */

enum short_modes {SHORT_DEFAULT=0, SHORT_PAUSE, SHORT_STRING};

read_write_t short_read (struct inode *inode, struct file *filp,
                char *buf, count_t count)
{
    int retval = count;
    unsigned port = short_base + (MINOR(inode->i_rdev)&0x0f);
    int mode = (MINOR(inode->i_rdev)&0x70) >> 4;
    unsigned char *kbuf=kmalloc(count, GFP_KERNEL), *ptr;
    
    if (!kbuf) return -ENOMEM;
    ptr=kbuf;

    switch(mode) {
      case SHORT_STRING:
#ifndef __alpha__ /* Alpha doesn'e export insb: fall through */
        insb(port, ptr, count);
        break;
#endif

      case SHORT_DEFAULT:
        while (count--)
            *(ptr++) = inb(port);
        break;

      case SHORT_PAUSE:
        while (count--)
            *(ptr++) = inb_p(port);
        break;

      default: /* no more modes defined by now */
        retval = -EINVAL;
        break;
    }
    if (retval > 0)
        copy_to_user(buf, kbuf, retval);
    kfree(kbuf);
    return retval;
}

read_write_t short_write (struct inode *inode, struct file *filp,
                const char *buf, count_t count)
{
    int retval = count;
    unsigned port = short_base + (MINOR(inode->i_rdev)&0x0f);
    int mode = (MINOR(inode->i_rdev)&0x70) >> 4;
    unsigned char *kbuf=kmalloc(count, GFP_KERNEL), *ptr;

    if (!kbuf) return -ENOMEM;
    copy_from_user(kbuf, buf, count);
    ptr=kbuf;

    switch(mode) {
      case SHORT_PAUSE:
        while (count--)
            outb_p(*(ptr++), port);
        break;

      case SHORT_STRING:
#ifndef __alpha__ /* Alpha doesn't export insb: fall through  */
        outsb(port, ptr, count);
        break;
#endif

      case SHORT_DEFAULT:
        while (count--)
            outb(*(ptr++), port);
        break;

      default: /* no more modes defined by now */
        retval = -EINVAL;
        break;
    }
    kfree(kbuf);
    return retval;
}

#ifdef __USE_OLD_SELECT__
int short_poll (struct inode *inode, struct file *filp,
                  int mode, select_table *table)
{
    return mode==SEL_EX ? 0 : 1; /* readable, writable, not-exceptionable */
}
#else
unsigned int short_poll (struct file *filp, poll_table *table)
{
    return POLLIN | POLLRDNORM | POLLOUT | POLLWRNORM;
}
#endif

struct file_operations short_fops = {
    NULL,          /* short_lseek */
    short_read,
    short_write,
    NULL,          /* short_readdir */
    short_poll,
    NULL,          /* short_ioctl */
    NULL,          /* short_mmap */
    short_open,
    short_release,
    NULL,          /* short_fsync */
    NULL,          /* short_fasync */
                   /* nothing more, fill with NULLs */
};

/* then,  the interrupt-related device */

read_write_t short_i_read (struct inode *inode, struct file *filp,
                char *buf, count_t count)
{
    int count0;

    while (short_head == short_tail) {
        interruptible_sleep_on(&short_queue);
        if (current->signal & ~current->blocked) /* a signal arrived */
          return -ERESTARTSYS; /* tell the fs layer to handle it */
        /* else, loop */
    }
    /* count0 is the number of readable data bytes */
    count0 = short_head - short_tail;
    if (count0 < 0) /* wrapped */
        count0 = short_buffer + PAGE_SIZE - short_tail;
    if (count0 < count) count = count0;

    copy_to_user(buf, (char *)short_tail, count);
    short_tail += count;
    if (short_tail == short_buffer + PAGE_SIZE)
        short_tail = short_buffer;
    return count;
}

read_write_t short_i_write (struct inode *inode, struct file *filp,
                const char *buf, count_t count)
{
    int written = 0, odd = filp->f_pos & 1;
    unsigned port = short_base; /* output to the parallel data latch */

    while (written < count)
        outb(0xff * ((++written + odd) & 1), port);

    filp->f_pos += count;
    return written;
}

struct file_operations short_i_fops = {
    NULL,          /* short_i_lseek */
    short_i_read,
    short_i_write,
    NULL,          /* short_i_readdir */
    NULL,          /* short_i_select */
    NULL,          /* short_i_ioctl */
    NULL,          /* short_i_mmap */
    short_open,
    short_release,
    NULL,          /* short_i_fsync */
    NULL,          /* short_i_fasync */
                   /* nothing more, fill with NULLs */
};

/*
 * The interrupt handler has a different prototype whether it
 * is compiled with kernels older or newer than 1.3.70
 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,70)
void short_interrupt(int irq, struct pt_regs *regs)
#else
void short_interrupt(int irq, void *dev_id, struct pt_regs *regs)
#endif
{
    struct timeval tv;
    do_gettimeofday(&tv);

    /* Write a 16 byte record. Assume PAGE_SIZE is a multiple of 16 */
    short_head += sprintf((char *)short_head,"%08u.%06u\n",
                          (int)(tv.tv_sec % 100000000), (int)(tv.tv_usec));
    if (short_head == short_buffer + PAGE_SIZE)
        short_head = short_buffer; /* wrap */

    wake_up_interruptible(&short_queue); /* awake any reading process */
}

/*
 * The following two functions are equivalent to the previous one,
 * but split in top and bottom half. First, a few needed variables
 */

#define NR_TIMEVAL 512 /* length of the array of time values */

struct timeval tv_data[NR_TIMEVAL]; /* too lazy to allocate it */
volatile struct timeval *tv_head=tv_data;
struct timeval *tv_tail=tv_data;

static struct tq_struct short_task; /* 0 by now, filled by init_module code */

int short_bh_count = 0;

void short_bottom_half(void *unused)
{
    int savecount = short_bh_count;
    short_bh_count = 0; /* we have already been removed from the queue */
    /*
     * The bottom half reads the tv array, filled by the top half,
     * and prints it to the circular text buffer, which is then consumed
     * by reading processes
     */

    /* First write the number of interrupts that occurred before this bh */

    short_head += sprintf((char *)short_head,"bh after %6i\n",savecount);
    if (short_head == short_buffer + PAGE_SIZE)
        short_head = short_buffer; /* wrap */

    /*
     * Then, write the time values. Write exactly 16 bytes at a time,
     * so it aligns with PAGE_SIZE
     */

    do {
        short_head += sprintf((char *)short_head,"%08u.%06u\n",
                              (int)(tv_tail->tv_sec % 100000000),
                              (int)(tv_tail->tv_usec));
        if (short_head == short_buffer + PAGE_SIZE)
            short_head = short_buffer; /* wrap */
        
        tv_tail++;
        if (tv_tail == (tv_data + NR_TIMEVAL) ) 
            tv_tail = tv_data; /* wrap */
        
    } while (tv_tail != tv_head);

    wake_up_interruptible(&short_queue); /* awake any reading process */
}


/*
 * use two implementations: before version 1.3.70 you couldn't
 * re-enqueue tasks, and "dev_id" was missing. I like re-enqueueing,
 * so I'd better keep the modern version clean
 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,70) /* old */
void short_bh_interrupt(int irq, struct pt_regs *regs)
{
    do_gettimeofday(tv_head);
    tv_head++;

    if (tv_head == (tv_data + NR_TIMEVAL) ) 
        tv_head = tv_data; /* wrap */

    /* Queue the bh. Don't re-enqueue */
    if (!short_bh_count)
        queue_task_irq_off(&short_task, &tq_immediate);
    mark_bh(IMMEDIATE_BH);

    short_bh_count++; /* record that an interrupt arrived */
}
#else /* recent */
void short_bh_interrupt(int irq, void *dev_id, struct pt_regs *regs)
{
    do_gettimeofday(tv_head);
    tv_head++;

    if (tv_head == (tv_data + NR_TIMEVAL) ) 
        tv_head = tv_data; /* wrap */

    /* Queue the bh. Don't care for multiple enqueueing */
    queue_task_irq_off(&short_task, &tq_immediate);
    mark_bh(IMMEDIATE_BH);

    short_bh_count++; /* record that an interrupt arrived */
}
#endif


#if LINUX_VERSION_CODE < VERSION_CODE(1,3,70)
void short_sh_interrupt(int irq, struct pt_regs *regs)
{
    void *dev_id = NULL;
#else
void short_sh_interrupt(int irq, void *dev_id, struct pt_regs *regs)
{
#endif
    int value;
    struct timeval tv;

    /* If it wasn't short, return immediately */
    value = inb(short_base);
    if (!(value & 0x80)) return;
        
    /* clear the interrupting bit */
    outb(value & 0x7F, short_base);

    /* the rest is unchanged */

    do_gettimeofday(&tv);
    short_head += sprintf((char *)short_head,"%08u.%06u\n",
                          (int)(tv.tv_sec % 100000000), (int)(tv.tv_usec));
    if (short_head == short_buffer + PAGE_SIZE)
        short_head = short_buffer; /* wrap */

    wake_up_interruptible(&short_queue); /* awake any reading process */
}

#if LINUX_VERSION_CODE >= VERSION_CODE(1,3,30)
void short_kernelprobe(void)
{
    int count = 0;
    do {
        unsigned long mask;

        mask = probe_irq_on();
        outb_p(0x10,short_base+2); /* enable reporting */
        outb_p(0x00,short_base);   /* clear the bit */
        outb_p(0xFF,short_base);   /* set the bit: interrupt! */
        outb_p(0x00,short_base+2); /* disable reporting */
        short_irq = probe_irq_off(mask);

        if (short_irq == 0) { /* none of them? */
            printk(KERN_INFO "short: no irq reported by probe\n");
            short_irq = -1;
        }
        /*
         * if more than one line has been activated, the result is
         * negative. We should service the interrupt (no need for lpt port)
         * and loop over again. Loop at most five times, then give up
         */
    } while (short_irq < 0 && count++ < 5);
    if (short_irq < 0)
        printk("short: probe failed %i times, giving up\n", count);
}
#else
void short_kernelprobe(void)
{
    printk(KERN_WARNING "short: kernel probing not available before 1.3.30\n");
}
#endif /* 1.3.30 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,70)
void short_probing(int irq, struct pt_regs *regs)
#else
void short_probing(int irq, void *dev_id, struct pt_regs *regs)
#endif
{
    if (short_irq == 0) short_irq = irq;    /* found */
    if (short_irq != irq) short_irq = -irq; /* ambiguous */
}

void short_selfprobe(void)
{
    int trials[] = {3, 5, 7, 9, 0};
    int tried[]  = {0, 0, 0, 0, 0};
    int i, count = 0;

     /*
      * install the probing handler for all possible lines. Remember
      * the result (0 for success, or -EBUSY) in order to only free
      * what has been acquired
      */
    for (i=0; trials[i]; i++)
        tried[i] = request_irq(trials[i], short_probing,
                               SA_INTERRUPT, "short probe", NULL);

    do {
        short_irq = 0; /* none got, yet */
        outb_p(0x10,short_base+2); /* enable */
        outb_p(0x00,short_base);
        outb_p(0xFF,short_base); /* toggle the bit */
        outb_p(0x10,short_base+2); /* disable */

        /* the value has been set by the handler */
        if (short_irq == 0) { /* none of them? */
            printk(KERN_INFO "short: no irq reported by probe\n");
        }
        /*
         * If more than one line has been activated, the result is
         * negative. We should service the interrupt (but the lpt port
         * doesn't need it) and loop over again. Do it at most 5 times
         */
    } while (short_irq <=0 && count++ < 5);

    /* end of loop, uninstall the handler */
    for (i=0; trials[i]; i++)
        if (tried[i] == 0)
            free_irq(trials[i], NULL);

    if (short_irq < 0)
        printk("short: probe failed %i times, giving up\n", count);
}
int init_module(void)
{
    int result = check_region(short_base,4);

    if (result) {
        printk(KERN_INFO "short: can't get I/O address 0x%x\n",short_base);
        return result;
    }
    request_region(short_base,4,"short");

    result = register_chrdev(short_major, "short", &short_fops);
    if (result < 0) {
        printk(KERN_INFO "short: can't get major number\n");
        release_region(short_base,4);
        return result;
    }
    if (short_major == 0) short_major = result; /* dynamic */

    short_buffer = __get_free_page(GFP_KERNEL); /* never fails */
    short_head = short_tail = short_buffer;

    /*
     * Fill the short_task structure, used for the bottom half handler
     */
    short_task.routine = short_bottom_half;
    short_task.data = NULL; /* unused */

    /*
     * Now we deal with the interrupt: either kernel-based
     * autodetection, DIY detection or default number
     */

    if (short_irq < 0 && probe == 1)
        short_kernelprobe();

    if (short_irq < 0 && probe == 2)
        short_selfprobe();

    if (short_irq < 0) /* not yet specified: force the default on */
        switch(short_base) {
          case 0x378: short_irq = 7; break;
          case 0x278: short_irq = 2; break;
          case 0x3bc: short_irq = 5; break;
        }

    /*
     * If shared has been specified, installed the shared handler
     * instead of the normal one. Do it first, before a -EBUSY will
     * force short_irq to -1.
     */
    if (short_irq >= 0 && share > 0) {
        free_irq(short_irq,NULL);
        result = request_irq(short_irq, short_sh_interrupt,
                             SA_SHIRQ | SA_INTERRUPT,"short",
                             short_sh_interrupt);
        if (result) {
            printk(KERN_INFO "short: can't get assigned irq %i\n", short_irq);
            short_irq = -1;
        }
        else { /* actually enable it -- assume this *is* a parallel port */
            outb(0x10,short_base+2);
        }
        return 0; /* the rest of the function only installs handlers */
    }

    if (short_irq >= 0) {
        result = request_irq(short_irq, short_interrupt,
                             SA_INTERRUPT, "short", NULL);
        if (result) {
            printk(KERN_INFO "short: can't get assigned irq %i\n",
                   short_irq);
            short_irq = -1;
        }
        else { /* actually enable it -- assume this *is* a parallel port */
            outb(0x10,short_base+2);
        }
    }

    /*
     * Ok, now change the interrupt handler if using top/bottom halves
     * has been requested
     */
    if (short_irq >= 0 && bh > 0) {
        free_irq(short_irq,NULL);
        result = request_irq(short_irq, short_bh_interrupt,
                             SA_INTERRUPT,"short-bh", NULL);
        if (result) {
            printk(KERN_INFO "short-bh: can't get assigned irq %i\n",
                   short_irq);
            short_irq = -1;
        }
    }

    return 0;
}

void cleanup_module(void)
{
    if (short_irq >= 0) {
        if (!share) free_irq(short_irq, NULL);
        else free_irq(short_irq, short_sh_interrupt);
    }
        
    unregister_chrdev(short_major, "short");
    release_region(short_base,4);
    if (short_buffer) free_page(short_buffer);
}


#endif /* __sparc__ */
