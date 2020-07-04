/*
 * master.c -- the master module of a master/slave pair using kmod
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
#  define MODVERSIONS /* force it on */
#endif

#ifdef MODVERSIONS
#  include <linux/modversions.h>
#endif

#include <linux/module.h>
#include <linux/version.h>

#include <linux/sched.h>
#include <linux/kernel.h> /* printk() */
#include <linux/string.h>
#include <linux/init.h>

#ifdef HAVE_INTER_MODULE                
static const char *inter_string = NULL;
static void master_test_inter();
#endif                                  


#include <linux/kmod.h>
#include "sysdep.h"


int master_init_module(void)
{
    int r[2]; /* results */
    
    r[0]=request_module("slave");
    r[1]=request_module("nonexistent");
    printk(KERN_INFO "master: loading results are %i, %i\n", r[0],r[1]);
#ifdef HAVE_INTER_MODULE                
    master_test_inter();		
#endif                                  
    return 0; /* success */
}

#ifndef HAVE_INTER_MODULE                
void master_cleanup_module(void)
{ }
#endif                                  



#ifdef HAVE_INTER_MODULE

void master_test_inter()
{
    void (*inter_func)();
    inter_string = inter_module_get_request("inter_string", "inter");
    if (inter_string)
        printk(KERN_INFO "master: got inter_string '%s'\n", inter_string);
    else
        printk(KERN_INFO "master: inter_module_get failed");
    inter_func = inter_module_get("inter_function");
    if (inter_func) {
	(*inter_func)("master");
	inter_module_put("inter_function");
    }
}	

void master_cleanup_module(void)
{
    if (inter_string)
        inter_module_put("inter_string");
}
#endif

module_init(master_init_module);
module_exit(master_cleanup_module);
