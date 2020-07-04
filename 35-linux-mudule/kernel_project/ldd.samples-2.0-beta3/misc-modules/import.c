/*
 * import.c -- a module using a symbol from export.c
 *
 *********/

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
#include "sysdep.h"

extern int export_function(int, int);

int import_init(void)
{
    int i = export_function(2,2);
    printk("import: my mate tells that 2+2 = %i\n",i);
    return 0;
}

void import_cleanup(void)
{}

module_init(import_init);
module_exit(import_cleanup);
