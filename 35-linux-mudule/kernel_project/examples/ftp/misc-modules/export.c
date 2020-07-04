/*
 * export.c -- export a symbol (maybe a versioned one)
 *
 * Tested with 2.0 on the x86, Sparc
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

/* This stuff might go in the Makefile, but I'd better put it here */

#ifndef EXPORT_SYMTAB
#  define EXPORT_SYMTAB /* need this one 'cause we export symbols */
#endif

#include <linux/autoconf.h> /* retrieve the CONFIG_* macros */
#if defined(CONFIG_MODVERSIONS) && !defined(MODVERSIONS)
#   define MODVERSIONS
#endif

/*
 * Include the versioned definitions for both kernel symbols and our
 * symbol, *unless* we are generating checksums (__GENKSYMS__
 * defined)
 */
#if defined(MODVERSIONS) && !defined(__GENKSYMS__)
#    include <linux/modversions.h>
#    include "export.ver" /* redefine "export_function" to include CRC */
#endif

/*
 * Everything from now on is normal. The previous stuff can be replaced
 * by "$(CC) -D__KERNEL__ -DMODULE -DMODVERSIONS -DEXPORT_SYMTAB \
 *         -include $(INCLUDEDIR)/linux/modversions.h" if versioning
 * is enabled, and the following (simpler) cmdline for genksyms:
 *    "$(CC) -E -DCONFIG_MODVERSIONS -DEXPORT_SYMTAB"
 */

#include <linux/module.h>
#ifndef LINUX_VERSION_CODE  /* I don't want compile errors with 1.2 */
#  include <linux/version.h>
#endif

#include "sysdep.h"

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,57)
#  error "This module needs Linux 1.3.57 or newer"
#else

#include <linux/sched.h>
#include <linux/kernel.h> /* printk() */
#include <linux/kerneld.h>

/* our dumb function, with two dumb arguments */
int export_function(int a, int b);


int init_module(void)
{
    static struct symbol_table export_syms = {
        #include <linux/symtab_begin.h>
        X(export_function),
        #include <linux/symtab_end.h>
    };
    register_symtab(&export_syms);

    return 0;
}

void cleanup_module(void)
{
}

int export_function(int a, int b)
{return a+b;}


#endif /* 1.3.57 or newer */
