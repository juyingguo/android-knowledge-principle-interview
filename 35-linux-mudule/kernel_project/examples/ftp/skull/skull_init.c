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

#include <linux/ioport.h>
#include <linux/errno.h>

#define __NO_VERSION__ /* don't define kernel_version in module.h */
#include <linux/module.h>
#include <linux/version.h>

char kernel_version [] = UTS_RELEASE;

#include <asm/system.h> /* cli(), *_flags */
#include <linux/kernel.h> /* printk */
#include <linux/errno.h> /* error codes */

/* have three symbols to export */
       void skull_fn1(void){}
static void skull_fn2(void){}
       int  skull_variable;

static int skull_register(void) /* and export them */
{
  static struct symbol_table skull_syms = {

#include <linux/symtab_begin.h>
        X(skull_fn1),
        X(skull_fn2),
        X(skull_variable),
#include <linux/symtab_end.h>
	};

  register_symtab(&skull_syms);
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


int init_module(void)
{
    /*
     * Print the isa region map, in blocks of 2k bytes.
     * This is not the best code, as it prints too many lines,
     * but it deserves to remain short to be included in the book.
     * Note also that read() should be used instead of pointers.
     */
    volatile unsigned char *ptr;  /* pointed data is volatile  */
    unsigned char oldval, newval; /* values read from memory   */
    unsigned long flags;          /* used to hold system flags */
    unsigned long add, i;
    
    /* probe all the memory hole in 2k steps */
    for (add = 0xA0000; add < 0x100000; add += 2048) {
	ptr = (unsigned char *)add;
	
	save_flags(flags);
	cli();
	oldval = *ptr;     /* read a byte */
	*ptr= oldval^0xff; /* change it   */
	newval=*ptr;       /* re-read     */
	*ptr=oldval;       /* restore     */
	restore_flags(flags);

	/* FIXME -- user getmem_fromio or such */
	if ((oldval^newval) == 0xff) {  /* we re-read our change: it's ram */
	    printk(KERN_INFO "%lx: RAM\n", (long)ptr);
	    continue;
	}
	if ((oldval^newval) != 0) {  /* random bits changed: it's empty */
	    printk(KERN_INFO "%lx: empty\n",(long)ptr);
	    continue;
	}
	
	/*
	 * Expansion rom (executed at boot time by the bios)
	 * has a signature of 0x55, 0xaa, and the third byte tells
	 * the size of such rom
	 */
	if ( (*ptr == 0x55) && (*(ptr+1) == 0xaa)) {
	    int size = 512 * *(ptr+2);
	    printk(KERN_INFO "%lx: Expansion ROM, %i bytes\n",
                   (long)ptr, size);
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
	printk(KERN_INFO "%lx: ", (long)ptr);
	for (i=0; i<5; i++) {
	    ptr+=57; /* a "random" value */
	    if (*ptr && *ptr!=0xFF && *ptr!=((long)ptr&0xFF))
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








