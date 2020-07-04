/*
 * slave.c -- the slave module of a master/slave pair using kerneld
 *
 * Tested with 2.0 on the x86, Sparc
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/module.h>

int init_module(void)
{return 0;}

void cleanup_module(void)
{}




