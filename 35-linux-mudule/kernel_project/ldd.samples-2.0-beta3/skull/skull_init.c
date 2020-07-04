/*
 * skull.c -- sample typeless module.
 *
 * BUGS:
 *   -it only runs on intel platforms.
 *   -readb() should be used (see short.c): skull doesn't work with 2.1
 *
 * Tested with 1.2 and 2.0 on the x86
 */

#ifndef __KERNEL__
#  define __KERNEL__
#endif
#ifndef MODULE
#  define MODULE
#endif

#ifndef EXPORT_SYMTAB
#  define EXPORT_SYMTAB
#endif
#include "sysdep.h"

#include <linux/ioport.h>
#include <linux/errno.h>

#include <linux/module.h>
#include <linux/version.h>

#include <asm/system.h> /* cli(), *_flags */
#include <linux/kernel.h> /* printk */
#include <linux/errno.h> /* error codes */

/* have three symbols to export */
       void skull_fn1(void){}
static void skull_fn2(void){}
       int  skull_variable;

#ifndef __USE_OLD_SYMTAB__
EXPORT_SYMBOL (skull_fn1);
EXPORT_SYMBOL (skull_fn2);
EXPORT_SYMBOL (skull_variable);
#endif

static int skull_register(void) /* and export them */
{
#ifdef __USE_OLD_SYMTAB__
  static struct symbol_table skull_syms = {

#include <linux/symtab_begin.h>
        X(skull_fn1),
        X(skull_fn2),
        X(skull_variable),
#include <linux/symtab_end.h>
	};

  register_symtab(&skull_syms);
#endif   /* __USE_OLD_SYMTAB__ */
  return 0;
}

/* perform hardware autodetection */
int skull_probe_hw(unsigned int port, unsigned int range)
{
   /* do smart probing here */
   return -1; /* not found  :-) */
}

/* perform hardware initalizazion */
int skull_init_board(unsigned int port)
{
  /* do smart initalization here */
  return 0; /* done :-) */
}

/* detect the the device if the region is still free */
static int skull_detect(unsigned int port, unsigned int range)
{
    int err;

    if ((err=check_region(port,range)) < 0) return err; /* busy */
    if (skull_probe_hw(port,range) != 0) return -ENODEV;   /* not found */
 
    request_region(port,range,"skull"); /* always succeeds */
    return 0;
}

/*
 * port ranges: the device can reside between
 * 0x280 and 0x300, in step of 0x10. It uses 0x10 ports.
 */
#define SKULL_PORT_FLOOR 0x280
#define SKULL_PORT_CEIL  0x300
#define SKULL_PORT_RANGE  0x010

/*
 * the following function performs autodetection, unless a specific
 * value was assigned by insmod to "skull_port_base"
 */

static int skull_port_base=0; /* 0 forces autodetection */
MODULE_PARM (skull_port_base, "i");
MODULE_PARM_DESC (skull_port_base, "Base I/O port for skull");


static int skull_find_hw(void) /* returns the # of devices */
{
    /* base is either the load-time value or the first trial */
    int base = skull_port_base ? skull_port_base 
                             : SKULL_PORT_FLOOR; 
    int result = 0;

    /* loop one time if value assigned, try them all if autodetecting */
    do {
	if (skull_detect(base, SKULL_PORT_RANGE) == 0) {
	    skull_init_board(base);
	    result++;
	}
	base += SKULL_PORT_RANGE; /* prepare for next trial */
    }
    while (skull_port_base == 0 && base < SKULL_PORT_CEIL);

    return result;
}


int skull_init(void)
{
    /*
     * Print the isa region map, in blocks of 2K bytes.
     * This is not the best code, as it prints too many lines,
     * but it deserves to remain short to be included in the book.
     * Note also that read() should be used instead of pointers.
     */
    unsigned char oldval, newval; /* values read from memory   */
    unsigned long flags;          /* used to hold system flags */
    unsigned long add, i;
    
    /* probe all the memory hole in 2KB steps */
    for (add = 0xA0000; add < 0x100000; add += 2048) {
	/*
	 * Check for an already allocated region.
	 */
	if (check_mem_region (add, 2048)) {
		printk(KERN_INFO "%lx: Allocated\n", add);
		continue;
	}
	/*
	 * Read and write the beginning of the region and see what happens.
	 */
	save_flags(flags); 
	cli();
	oldval = isa_readb (add);  /* Read a byte */
	isa_writeb (oldval^0xff, add);
	mb();
	newval = isa_readb (add);
	isa_writeb (oldval, add);
	restore_flags(flags);

	if ((oldval^newval) == 0xff) {  /* we re-read our change: it's ram */
	    printk(KERN_INFO "%lx: RAM\n", add);
	    continue;
	}
	if ((oldval^newval) != 0) {  /* random bits changed: it's empty */
	    printk(KERN_INFO "%lx: empty\n", add);
	    continue;
	}
	
	/*
	 * Expansion rom (executed at boot time by the bios)
	 * has a signature where the first byt is 0x55, the second 0xaa,
	 * and the third byte indicates the size of such rom
	 */
	if ( (oldval == 0x55) && (isa_readb (add + 1) == 0xaa)) {
	    int size = 512 * isa_readb (add + 2);
	    printk(KERN_INFO "%lx: Expansion ROM, %i bytes\n",
                   add, size);
	    add += (size & ~2048) - 2048; /* skip it */
	    continue;
	}
	
	/*
	 * If the tests above failed, we still don't know if it is ROM or
	 * empty. Since empty memory can appear as 0x00, 0xff, or the low
	 * address byte, we must probe multiple bytes: if at least one of
	 * them is different from these three values, then this is rom
	 * (though not boot rom).
	 */
	printk(KERN_INFO "%lx: ", add);
	for (i=0; i<5; i++) {
	    unsigned long radd = add + 57*(i+1);  /* a "random" value */
	    unsigned char val = isa_readb (radd);
	    if (val && val != 0xFF && val != ((unsigned long) radd&0xFF))
		break;
	}    
	printk("%s\n", i==5 ? "empty" : "ROM");
    }

    /*
     * Find you hardware 
     */
    skull_find_hw();

    /*
     * Always fail to load (or suceed).
     */
    skull_register(); /* register your symbol table */
    return 0;
}

module_init(skull_init);
