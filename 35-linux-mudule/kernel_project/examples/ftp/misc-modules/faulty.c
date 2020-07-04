/*
 * faulty.c -- a module which generates an oops when read
 *
 * Tested with 1.2 on the x86
 * Tested with 2.0 on the x86, Sparc
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

#include <linux/kernel.h> /* printk() */
#include <linux/fs.h>     /* everything... */
#include <linux/types.h>  /* size_t */
#include <asm/segment.h>

#include "sysdep.h" /* count_t for portability 2.0/2.1 */

int faulty_major=0;

char faulty_buf[1024];

read_write_t faulty_read (struct inode *inode, struct file *filp,
                char *buf, count_t count)
{
  printk(KERN_DEBUG "read: inode %p, file %p, buf %p, count %li\n",
         inode, filp, buf, (long)count);
  memcpy_tofs(buf,faulty_buf,count);
  return count;
}
struct pio {int a; char b; long c;};

read_write_t faulty_write (struct inode *inode, struct file *filp,
               const char *buf, count_t count)
{
    /* put_user(0,(struct pio *)buf);*/
    return 0;
}


struct file_operations faulty_fops = {
    NULL,          /* lseek */
    faulty_read,
    faulty_write,
                   /* nothing more, fill with NULLs */
};


int init_module(void)
{
    int result;

    /*
     * Register your major, and accept a dynamic number
     */
    result = register_chrdev(faulty_major, "faulty", &faulty_fops);
    if (result < 0) return result;
    if (faulty_major == 0) faulty_major = result; /* dynamic */

    /* 
     * allocate the devices -- we can't have them static, as the number
     * can be specified at load time
     */
    return 0;
}

void cleanup_module(void)
{
    unregister_chrdev(faulty_major, "faulty");
}



