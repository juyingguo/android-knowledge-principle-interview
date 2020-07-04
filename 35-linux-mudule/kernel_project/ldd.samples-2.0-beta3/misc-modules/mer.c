#define __KERNEL__
#define MODULE
#include <linux/module.h>
#include <linux/errno.h>
int init_module(void)      { return -EPERM; }
void cleanup_module(void)  {}
