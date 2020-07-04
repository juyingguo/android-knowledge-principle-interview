/*
 * jiq.c -- the just-in-queue module
 *
 * Tested with 2.0 on the x86, Sparc
 */
 
/* BUGS: the module is not reentrant: only one file can be read at a time
 *       the module usage count is not used: you could remove the module
 *           while reading it, thus asking for troubles.
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
#include <linux/kernel.h>
#include <linux/fs.h>     /* everything... */
#include <linux/proc_fs.h>
#include <linux/errno.h>  /* error codes */
#include <linux/tqueue.h>
#include <linux/interrupt.h> /* intr_count */

/*
 * This module is a silly one: it only embeds short code fragments
 * that show how enqueued tasks `feel' theit environment
 */

#define LIMIT (PAGE_SIZE-128) /* don't print any more after this size */

/*
 * Print information about the current environment. This is called from
 * within the task queues. If the limit is reched, awake the reading
 * process.
 */

struct wait_queue *jiq_wait;


struct tq_struct jiq_task; /* global: initialized to zero */

struct clientdata {
    int len;
    char *buf;
    unsigned long jiffies;
    task_queue *queue;
} jiq_data;

void jiq_print(void *ptr)
{
  struct clientdata *data = (struct clientdata *)ptr;
  int len = data->len;
  char *buf = data->buf;
  unsigned long j = jiffies;

  if (len > LIMIT) {
      wake_up_interruptible(&jiq_wait);
      return;
  }

  if (len == 0)
      len = sprintf(buf,"    time  delta intr_count pid command\n");
  else
      len =0;

  /* intr_count is only exported since 1.3.5, but 1.99.4 is needed anyways */
  len += sprintf(buf+len,"%9li %3li        %li   %5i %s\n",
                 j, j - data->jiffies,
                 intr_count, current->pid, current->comm);

  data->len += len;
  data->buf += len;
  data->jiffies = j;

  /* re-register yourself, if needed */
  if (data->queue)
      queue_task(&jiq_task, data->queue);
  if (data->queue == &tq_immediate)
      mark_bh(IMMEDIATE_BH); /* this one needs to be marked */
}

/*
 * Use the scheduler queue  -- /proc/jiqsched
 */

int jiq_read_sched(char *buf, char **start, off_t offset,
                   int len, int unused)
{

    jiq_data.len = 0;               /* nothing printed, yet */
    jiq_data.buf = buf;             /* print in this place */
    jiq_data.jiffies = jiffies;     /* initial time */

    /* jiq_print will queue_task() again in jiq_data.queue */
    jiq_data.queue = &tq_scheduler;

    queue_task(&jiq_task, &tq_scheduler); /* ready to run */
    interruptible_sleep_on(&jiq_wait);    /* sleep till completion */

    return jiq_data.len;
}

struct proc_dir_entry jiq_proc_sched = {
        0,                 /* low_ino: the inode -- dynamic */
        8, "jiqsched",     /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &jiq_read_sched,   /* function used to read data */
        /* nothing more */
    };


int jiq_read_timer(char *buf, char **start, off_t offset,
                   int len, int unused)
{

    jiq_data.len = 0;            /* nothing printed, yet */
    jiq_data.buf = buf;          /* print in this place */
    jiq_data.jiffies = jiffies;  /* initial time */
    jiq_data.queue = &tq_timer;  /* re-register yourself here */

    queue_task(&jiq_task, &tq_timer);     /* ready to run */
    interruptible_sleep_on(&jiq_wait);    /* sleep till completion */

    return jiq_data.len;
}

struct proc_dir_entry jiq_proc_timer = {
        0,                 /* low_ino: the inode -- dynamic */
        8, "jiqtimer",     /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &jiq_read_timer,   /* function used to read data */
        /* nothing more */
    };

int jiq_read_immed(char *buf, char **start, off_t offset,
                   int len, int unused)
{

    jiq_data.len = 0;                /* nothing printed, yet */
    jiq_data.buf = buf;              /* print in this place */
    jiq_data.jiffies = jiffies;      /* initial time */
    jiq_data.queue = &tq_immediate;  /* re-register yourself here */

    queue_task(&jiq_task, &tq_immediate); /* ready to run */
    mark_bh(IMMEDIATE_BH);
    interruptible_sleep_on(&jiq_wait);    /* sleep till completion */

    return jiq_data.len;
}

struct proc_dir_entry jiq_proc_immed = {
        0,                 /* low_ino: the inode -- dynamic */
        8, "jiqimmed",     /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &jiq_read_immed,   /* function used to read data */
        /* nothing more */
    };



/*
 * This one, instead, tests out the timers.
 */

struct timer_list jiq_timer;

void jiq_timedout(unsigned long ptr)
{
    jiq_print((void *)ptr);            /* print a line */
    wake_up_interruptible(&jiq_wait);  /* awake the process */
}


int jiq_read_run_timer(char *buf, char **start, off_t offset,
                   int len, int unused)
{

    jiq_data.len = 0;           /* prepare the argument for jiq_print() */
    jiq_data.buf = buf;
    jiq_data.jiffies = jiffies;
    jiq_data.queue = NULL;      /* don't requeue */

    init_timer(&jiq_timer);              /* init the timer structure */
    jiq_timer.function = jiq_timedout;
    jiq_timer.data = (unsigned long)&jiq_data;
    jiq_timer.expires = jiffies + HZ; /* one second */

    jiq_print(&jiq_data);   /* print and go to sleep */
    add_timer(&jiq_timer);
    interruptible_sleep_on(&jiq_wait);
    return jiq_data.len;
}

struct proc_dir_entry jiq_proc_run_timer = {
        0,                 /* low_ino: the inode -- dynamic */
        7, "jitimer",      /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &jiq_read_run_timer, /* function used to read data */
        /* nothing more */
    };


/*
 * the init/clean material
 */

int init_module(void)
{
    /* this lines are in init_module() */
    jiq_task.routine = jiq_print;
    jiq_task.data = (void *)&jiq_data;

    proc_register_dynamic(&proc_root, &jiq_proc_sched);
    proc_register_dynamic(&proc_root, &jiq_proc_timer);
    proc_register_dynamic(&proc_root, &jiq_proc_immed);
    proc_register_dynamic(&proc_root, &jiq_proc_run_timer);



#ifndef JIT_DEBUG
    register_symtab(NULL); /* hide symbols */
#endif
    return 0; /* succeed */
}

void cleanup_module(void)
{
    proc_unregister(&proc_root, jiq_proc_sched.low_ino);
    proc_unregister(&proc_root, jiq_proc_timer.low_ino);
    proc_unregister(&proc_root, jiq_proc_immed.low_ino);
    proc_unregister(&proc_root, jiq_proc_run_timer.low_ino);
}

#endif /* version 1.99.4 or newer */
