/*
 * stepper.c -- char module
 *
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

#include <linux/kernel.h> /* printk() */
#include <linux/malloc.h> /* kmalloc() */
#include <linux/fs.h>     /* everything... */
#include <linux/errno.h>  /* error codes */
#include <linux/types.h>  /* size_t */
#include <linux/stat.h>   /* S_IFREG */
#include <linux/proc_fs.h>
#include <linux/ioport.h>
#include <linux/tqueue.h>

#include <asm/system.h>   /* cli(), *_flags */
#include <asm/segment.h>
#include <asm/io.h>

#include "stepper.h"        /* local definitions */
#include "sysdep.h"

int stepper_major =   STEP_MAJOR;
int step_x, step_y, step_tx, step_ty, step_speed, step_d[4], step_l;

int step_unloading=0;

struct tq_struct step_tq;

int step_svec[]={100,75,50,25,20, 10,8,6,4,2};

short digits[10]={0x7D,0x44,0x6B,0x6E,0x56,0x3E,0x3F,0x64,0x7F,0x7E};
unsigned char data[4];

void step_tick(void *unused)
{
    int doit=0;
    static unsigned long lasttick;

#ifdef STEP_DEBUG
    if (jiffies%1000 == 0) {
        PDEBUG("live: %i %i (%i %i) %i -- %c%c:%c%c L %02i\n",
               step_x, step_y, step_tx, step_ty, step_speed,
               step_d[0], step_d[1], step_d[2], step_d[3], step_l);
        PDEBUG("last %li, %li ago\n",lasttick,jiffies-lasttick);
    }
#endif

    if (jiffies%50 == 0) {
        data[0]^=1; /* tick */
        data[0]|=0x1e;
        if ( (jiffies/100) & 3) { /* minutes */
            data[1]=digits[step_d[2]-'0'];
            data[2]=digits[step_d[3]-'0'];
        } else { /* hour */
            data[1]=digits[step_d[0]-'0'];
            data[2]=digits[step_d[1]-'0'] | 0x80;
        }
        doit=1;
    }
    if (jiffies - lasttick > step_svec[step_speed] &&
        ((step_x != step_tx) || (step_y != step_ty))) {
        if (step_tx > step_x)
            step_x++;
        if (step_ty > step_y)
            step_y++;
        if (step_tx < step_x)
            step_x--;
        if (step_ty < step_y)
            step_y--;
        data[3]= (step_x&7) | ((step_y&7)*16);
        lasttick=jiffies;
        doit=1;
    }
    if (doit) {
        doit=0;
        outb_p(data[3],0x281);
        outb_p(data[0]|0x80,0x280);
        outb_p(data[2],0x281);
        outb_p(data[0]|0x40,0x280);
        outb_p(data[1],0x281);
        outb_p(data[0]|0x20,0x280);

        outb_p(data[0],0x280);
    }
            
    if (!step_unloading)
        queue_task(&step_tq,&tq_timer);
    else
        PDEBUG("not queueing\n");
    

}

/*
 * The proc filesystem: function to read and entry
 */

int stepper_read_proc(char *buf, char **start, off_t offset,
                   int len, int unused)
{
    len=sprintf(buf,"%i %i (%i %i) %i -- %c%c:%c%c L %02i\n",
                step_x, step_y, step_tx, step_ty, step_speed,
                step_d[0], step_d[1], step_d[2], step_d[3], step_l);
    return len;
}

struct proc_dir_entry stepper_proc_entry = {
        0,                 /* low_ino: the inode -- dynamic */
        8, "stepper",     /* len of name and name */
        S_IFREG | S_IRUGO, /* mode */
        1, 0, 0,           /* nlinks, owner, group */
        0, NULL,           /* size - unused; operations -- use default */
        &stepper_read_proc,   /* function used to read data */
        /* nothing more */
    };

/*
 * Open and close -- I don't use them
 */

int stepper_open (struct inode *inode, struct file *filp)
{
    PDEBUG("open\n");
    MOD_INC_USE_COUNT;
    return 0;          /* success */
}

void stepper_release (struct inode *inode, struct file *filp)
{
    PDEBUG("close\n");
    MOD_DEC_USE_COUNT;
}

/*
 * Data management: read and write
 */

read_write_t stepper_read (struct inode *inode, struct file *filp,
                char *buf, count_t count)
{
return 0;
#if 0

    PDEBUG("read %i (pos is %li, size is %i)\n",count,f_pos,dev->size);
    if (f_pos > dev->size)
        return 0;
    if (f_pos + count > dev->size)
        count = dev->size - f_pos;
    /* find listitem, qset index and offset in the quantum */
    item = f_pos / itemsize;
    rest = f_pos % itemsize;
    s_pos = rest / quantum; q_pos = rest % quantum;
    PDEBUG("read at %i:%i:%i\n",item,s_pos,q_pos);

    /* follow the list up to the right position (defined elsewhere) */
    dev = stepper_follow(dev, item);
    if (!dev->data)
        return 0; /* don't fill holes */
    if (!dev->data[s_pos])
        return 0;
    if (count > quantum - q_pos)
        count = quantum - q_pos; /* read only up to the end of this quantum */
    memcpy_tofs(buf, dev->data[s_pos]+q_pos, count);
    filp->f_pos += count;
    PDEBUG("read %i, pos is %li\n",count,(unsigned long)filp->f_pos);
    return count;
#endif
}

int step_dispatch (int x, int y)
{
    PDEBUG("move %i %i\n",x,y);
    step_tx+=x;
    step_ty+=y;
    return 0;
}

int step_off(void)
{
    PDEBUG("off\n");
    data[3]=0x88;
    return 0;
}

int step_setspeed(int s)
{
    PDEBUG("speed is %i\n",s);
    if (s>=0 && s<=9)
        step_speed=s;
    return 0;
}


read_write_t stepper_write (struct inode *inode, struct file *filp,
                const char *buf, count_t count)
{
    const char *datum = buf;
    char cmd, sign;
    int n, x, y;
    int got=0;

#define STEP_GET() ({char c; c=get_user(datum); datum++; count--; got++; c;})
#define STEP_PEEK() (get_user(datum))

    while (count) {
        switch( cmd=STEP_GET() ) {
        case 'l': case 'r': case 'u': case 'd':
        case 'L': case 'R': case 'U': case 'D':
        case 'x': case 'y':
            n=0; sign=1;
            if (STEP_PEEK()=='-') { STEP_GET(); sign=-1; }
            while (count && STEP_PEEK() >= '0' && STEP_PEEK() <= '9') {
                n=n*10+(STEP_GET()-'0');
            }
            n*=sign;
            PDEBUG("%c %i\n",cmd, n);

            if (cmd == 'x') step_tx = n;
            if (cmd == 'y') step_ty = n;

            if (cmd>='A' && cmd <= 'Z') { n*=10; cmd += 'a' - 'A'; }
            x=0 + (cmd=='r' ? n : 0) - (cmd=='l' ? n : 0);
            y=0 + (cmd=='u' ? n : 0) - (cmd=='d' ? n : 0);
            step_dispatch(x,y);
            break;

        case '-':
            step_off(); break;

        case 's': case 'S':
            n=0;
            if (count) n=STEP_GET()-'0';
            step_setspeed(n);
            break;

        case '!':
            step_x = step_y = step_tx = step_ty = 0;
            break;

        case 'T':
            for (n=0; n<4; n++) {
                while(count) {
                    step_d[n]=STEP_GET();
                    if (step_d[n]>='0' && step_d[n]<='9')
                        break;
                }
                if (!count) break;
            }
            PDEBUG("digits are %c%c%c%c\n",
                step_d[0], step_d[1], step_d[2], step_d[3]);
            break;

        case 'M':
            n=0;
            while (count && (cmd=STEP_GET()) != '\n') {
                if (cmd>='0' && cmd <='9') 
                    n=n*10+(cmd-'0');
            }
            PDEBUG("load is %i\n",n);
            step_l=n/50;
            break;

        case ' ': case ';': case '\t': case '\n': case ',':
            break;
        default:
            PDEBUG("unknown cmd '%c'\n",cmd);
        }
    }
    PDEBUG("written %i\n",got);
    return got;
}


/*
 * The file operations
 */

struct file_operations stepper_fops = {
    NULL,          /* stepper_lseek */
    stepper_read,
    stepper_write,
    NULL,          /* stepper_readdir */
    NULL,          /* stepper_select */
    NULL,          /* stepper_ioctl */
    NULL,          /* stepper_mmap */
    stepper_open,
    stepper_release,
                   /* nothing more, fill with NULLs */
};

/*
 * Finally, the module stuff
 */

int init_module(void)
{
    int result;

    /*
     * Register your major, and accept a dynamic number (is so asked)
     */
    result = register_chrdev(stepper_major, "stepper", &stepper_fops);
    if (result < 0) return result;
    if (stepper_major == 0) stepper_major = result; /* dynamic */

    request_region(0x280,2,"stepper");

    step_tq.routine = step_tick;
    step_tq.data = NULL;
    queue_task(&step_tq,&tq_timer);

#ifdef STEP_USE_PROC
    proc_register_dynamic(&proc_root, &stepper_proc_entry);
#endif
#ifndef STEP_DEBUG
    register_symtab(NULL);
#endif
    return 0;
}

void cleanup_module(void)
{
    unsigned long j=jiffies;

    step_unloading=1;
    while (jiffies < j+10)
        schedule();

    unregister_chrdev(stepper_major, "stepper");
    release_region(0x280,2);

#ifdef STEP_USE_PROC
    proc_unregister(&proc_root, stepper_proc_entry.low_ino);
#endif

}




