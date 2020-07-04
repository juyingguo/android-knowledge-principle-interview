/*
 * inter.c -- A slave variant that uses inter_module functions
 * $Id: inter.c,v 1.2 2000/11/17 21:21:53 corbet Exp $
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/module.h>
#include <linux/init.h>
#include "sysdep.h"

#ifdef HAVE_INTER_MODULE

static char *string = "inter says 'Hello World'";

void inter_function(const char *who)
{
    printk(KERN_INFO "inter: inter_function called by %s\n", who);
}

int inter_init(void)
{
    inter_module_register("inter_string", THIS_MODULE, string);
    inter_module_register("inter_function", THIS_MODULE, inter_function);
    return 0;
}

void inter_cleanup(void)
{
    inter_module_unregister("inter_string");
}


module_init(inter_init);
module_exit(inter_cleanup);
#endif


