/*
 * import.c -- a module using a symbol from export.c (v2.1)
 *
 * Tested with 2.1.43 on the x86 (novers)
 */


#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

/*
 * Use versioning if needed
 */
#include <linux/autoconf.h> /* retrieve the CONFIG_* macros */
#ifdef CONFIG_MODVERSIONS
#   undef MODVERSIONS /* it might be defined */
#   define MODVERSIONS
#endif

#ifdef MODVERSIONS
#  include <linux/modversions.h>
#  include "export.ver"
#endif


#include <linux/module.h>

#include <linux/kernel.h>

extern int export_function(int, int);

int init_module(void)
{
    int i = export_function(2,2);
    printk("import: my mate tells that 2+2 = %i\n",i);
    return 0;
}

void cleanup_module(void)
{}




