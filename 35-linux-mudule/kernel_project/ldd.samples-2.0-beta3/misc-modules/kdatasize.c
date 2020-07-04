/*
 * kdatasize.c -- print the size of common data items from kernel space
 *
 * This runs with any Linux kernel (not any Unix, because of <linux/types.h>)
 */
#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/module.h>

#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/utsname.h>
#include <linux/errno.h>

void cleanup_module(void)
{ /* never used */ }

int init_module(void)
{
    /* print information and return an error */
    printk("arch   Size:  char  short  int  long   ptr long-long "
	   " u8 u16 u32 u64\n");
    printk(       "%-12s  %3i   %3i   %3i   %3i   %3i   %3i      "
	   "%3i %3i %3i %3i\n",
	   system_utsname.machine,
	   (int)sizeof(char), (int)sizeof(short), (int)sizeof(int),
	   (int)sizeof(long),
	   (int)sizeof(void *), (int)sizeof(long long), (int)sizeof(__u8),
	   (int)sizeof(__u16), (int)sizeof(__u32), (int)sizeof(__u64));
    return -ENODEV;
}
