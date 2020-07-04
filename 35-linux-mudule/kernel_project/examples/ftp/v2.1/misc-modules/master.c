/*
 * master.c -- the master module of a master/slave pair using kerneld (v2.1)
 *
 * Tested with 2.1.43 on the x86
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

/*
 * Inclusions related to version problems. They *might* go after
 * <linux/module.h>, unless a symbol table is exported. All in all,
 * better putting them first anyways.
 */
#include <linux/autoconf.h> /* retrieve the CONFIG_* macros */
#if defined(CONFIG_MODVERSIONS) && !defined(MODVERSIONS)
#   define MODVERSIONS /* force it on */
#endif

#ifdef MODVERSIONS
#  include <linux/modversions.h>
#endif

#include <linux/module.h>
#ifndef LINUX_VERSION_CODE  /* I don't want compile errors with 1.2 */
#  include <linux/version.h>
#endif

# include "sysdep-2.1.h"

#include <linux/sched.h>
#include <linux/kernel.h> /* printk() */
#include <linux/string.h>

#include <linux/kerneld.h>

int init_module(void)
{
    int r[3]; /* results */

    r[0]=request_module("slave");
    r[1]=request_module("slaveD");
    r[2]=request_module("unexists");
    printk("master: loading results are %i, %i, %i\n",
           r[0],r[1],r[2]);
    return 0; /* success */
}

void cleanup_module(void)
{
    int r[4]; /* results */

    r[0]=release_module("slave", 1 /* wait */);
    r[1]=release_module("slaveH", 1 /* wait */);
    r[2]=delayed_release_module("slaveD");
    r[3]=release_module("unexists", 1 /* wait */);
    printk("master: unloading results are %i, %i, %i, %i\n",
           r[0],r[1],r[2],r[3]); 
}
