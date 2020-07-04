
/*
 * stepper.h -- definitions for the char module
 *
 *********/

/*
 * Macros to help debugging
 */

#undef PDEBUG             /* undef it, just in case */
#ifdef STEP_DEBUG
#  ifdef __KERNEL__
     /* This one if debugging is on, and kernel space */
#    define PDEBUG(fmt, args...) printk( KERN_DEBUG "step: " fmt, ## args)
#  else
     /* This one for user space */
#    define PDEBUG(fmt, args...) fprintf(stderr, fmt, ## args)
#  endif
#else
#  define PDEBUG(fmt, args...) /* not debugging: nothing */
#endif

#undef PDEBUGG
#define PDEBUGG(fmt, args...) /* nothing: it's a placeholder */


#define STEP_MAJOR 60 /* not dynamic major by default */

struct file_operations step_fops;        /* simplest: global */

#undef STEP_USE_PROC
