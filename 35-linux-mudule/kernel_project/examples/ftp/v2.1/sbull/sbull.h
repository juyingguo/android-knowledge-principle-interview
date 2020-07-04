
/*
 * sbull.h -- definitions for the char module
 *
 *********/


#include <linux/ioctl.h>

/* version dependencies have been confined to a separate file */

#include "sysdep-2.1.h"

/*
 * Macros to help debugging
 */

#undef PDEBUG             /* undef it, just in case */
#ifdef SBULL_DEBUG
#  ifdef __KERNEL__
     /* This one if debugging is on, and kernel space */
#    define PDEBUG(fmt, args...) printk( KERN_DEBUG "sbull: " fmt, ## args)
#  else
     /* This one for user space */
#    define PDEBUG(fmt, args...) fprintf(stderr, fmt, ## args)
#  endif
#else
#  define PDEBUG(fmt, args...) /* not debugging: nothing */
#endif

#undef PDEBUGG
#define PDEBUGG(fmt, args...) /* nothing: it's a placeholder */


#define SBULL_MAJOR 0       /* dynamic major by default */
#define SBULL_DEVS 2        /* two disks */
#define SBULL_RAHEAD 2      /* two sectors */
#define SBULL_SIZE 2048     /* two megs each */
#define SBULL_BLKSIZE 1024  /* 1k blocks */
#define SBULL_HARDSECT 512  /* FIXME -- are 1k hardware sectors doable??? */

/*
 * The sbull device is removable: if it is left closed for more than
 * half a minute, it is removed. Thus use a usage count and a
 * kernel timer
 */

typedef struct Sbull_Dev {
   int size;
   int usage;
   struct timer_list timer;
   u8 *data;
}              Sbull_Dev;




