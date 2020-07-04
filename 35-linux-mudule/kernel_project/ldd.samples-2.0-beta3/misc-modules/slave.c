/*
 * slave.c -- the slave module of a master/slave pair using kerneld
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#include <linux/module.h>
#include "sysdep.h"

int slave_init(void)
{
	MOD_INC_USE_COUNT;
	MOD_DEC_USE_COUNT;  /* Make it look "used once" */
	return 0;
}

void slave_cleanup(void)
{}

module_init(slave_init);
module_exit(slave_cleanup);


