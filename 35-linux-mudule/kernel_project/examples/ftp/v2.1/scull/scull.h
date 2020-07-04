
/*
 * scull.h -- definitions for the char module
 *
 *********/

#include <linux/ioctl.h>

/* version dependencies have been confined to a separate file */

#include "sysdep-2.1.h"


/*
 * Macros to help debugging
 */

#undef PDEBUG             /* undef it, just in case */
#ifdef SCULL_DEBUG
#  ifdef __KERNEL__
     /* This one if debugging is on, and kernel space */
#    define PDEBUG(fmt, args...) printk( KERN_DEBUG "scull: " fmt, ## args)
#  else
     /* This one for user space */
#    define PDEBUG(fmt, args...) fprintf(stderr, fmt, ## args)
#  endif
#else
#  define PDEBUG(fmt, args...) /* not debugging: nothing */
#endif

#undef PDEBUGG
#define PDEBUGG(fmt, args...) /* nothing: it's a placeholder */

#ifndef SCULL_MAJOR
#define SCULL_MAJOR 0   /* dynamic major by default */
#endif

#ifndef SCULL_NR_DEVS
#define SCULL_NR_DEVS 4    /* scull0 through scull3 */
#endif

#ifndef SCULL_P_NR_DEVS
#define SCULL_P_NR_DEVS 4  /* scullpipe0 through scullpipe3 */
#endif

/*
 * The bare device is a variable-length region of memory.
 * Use a linked list of indirect blocks.
 *
 * "Scull_Dev->data" points to an array of pointers, each
 * pointer refers to a memory area of SCULL_QUANTUM bytes.
 *
 * The array (quantum-set) is SCULL_QSET long.
 */
#ifndef SCULL_QUANTUM
#define SCULL_QUANTUM 4000
#endif

#ifndef SCULL_QSET
#define SCULL_QSET    1000
#endif

/*
 * The pipe device is a simple circular buffer. Here its default size
 */
#ifndef SCULL_P_BUFFER
#define SCULL_P_BUFFER 4000
#endif

typedef struct Scull_Dev {
   void **data;
   struct Scull_Dev *next;   /* next listitem */
   int quantum;              /* the current quantum size */
   int qset;                 /* the current array size */
   unsigned long size;
   unsigned int access_key;  /* used by sculluid and scullpriv */
   unsigned int usage;       /* lock the device while using it */
} Scull_Dev;

/*
 * Split minors in two parts
 */
#define TYPE(dev)   (MINOR(dev) >> 4)  /* high nibble */
#define NUM(dev)    (MINOR(dev) & 0xf) /* low  nibble */

/*
 * Different minors behave differently, so let's use multiple fops
 */

extern struct file_operations scull_fops;        /* simplest: global */
extern struct file_operations scull_priv_fops;   /* private region   */
extern struct file_operations scull_pipe_fops;   /* circular buffer  */
extern struct file_operations scull_sngl_fops;   /* single open      */
extern struct file_operations scull_user_fops;   /* single process   */
extern struct file_operations scull_wusr_fops;   /* single user      */

/*
 * The different configurable parameters
 */
extern int scull_major;     /* main.c */
extern int scull_nr_devs;
extern int scull_quantum;
extern int scull_qset;

extern int scull_p_nr_devs;    /* pipe.c */
extern int scull_p_buffer;

/*
 * Prototypes for shared functions
 */

int scull_p_init(void);
void scull_p_cleanup(void);
int scull_access_init(void);
void scull_access_cleanup(void);

int scull_trim(Scull_Dev *dev);

read_write_t scull_read (struct inode *inode, struct file *filp,
                char *buf, count_t count);
read_write_t scull_write (struct inode *inode, struct file *filp,
                const char *buf, count_t count);
lseek_t scull_lseek (struct inode *inode, struct file *filp,
                 lseek_off_t off, int whence);
int scull_ioctl (struct inode *inode, struct file *filp,
                 unsigned int cmd, unsigned long arg);


#ifdef SCULL_DEBUG
#  if LINUX_VERSION_CODE > VERSION_CODE(1,99,3) /* 1.99.4 exported the needed symbols */
#    define SCULL_USE_PROC
#  endif
#endif

#ifndef min
#  define min(a,b) ((a)<(b) ? (a) : (b))
#endif

/*
 * Ioctl definitions
 */

/* Use 'k' as magic number */
#define SCULL_IOC_MAGIC  'k'

#define SCULL_IOCRESET    _IO(SCULL_IOC_MAGIC, 0)

/*
 * S means "Set" through a ptr,
 * T means "Tell" directly with the argument value
 * G means "Get": reply by setting through a pointer
 * Q means "Query": response is on the return value
 * X means "eXchange": G and S atomically
 * H means "sHift": T and Q atomically
 */
#define SCULL_IOCSQUANTUM _IOW(SCULL_IOC_MAGIC,  1, scull_quantum)
#define SCULL_IOCSQSET    _IOW(SCULL_IOC_MAGIC,  2, scull_qset)
#define SCULL_IOCTQUANTUM _IO(SCULL_IOC_MAGIC,   3)
#define SCULL_IOCTQSET    _IO(SCULL_IOC_MAGIC,   4)
#define SCULL_IOCGQUANTUM _IOR(SCULL_IOC_MAGIC,  5, scull_quantum)
#define SCULL_IOCGQSET    _IOR(SCULL_IOC_MAGIC,  6, scull_qset)
#define SCULL_IOCQQUANTUM _IO(SCULL_IOC_MAGIC,   7)
#define SCULL_IOCQQSET    _IO(SCULL_IOC_MAGIC,   8)
#define SCULL_IOCXQUANTUM _IOWR(SCULL_IOC_MAGIC, 9, scull_quantum)
#define SCULL_IOCXQSET    _IOWR(SCULL_IOC_MAGIC,10, scull_qset)
#define SCULL_IOCHQUANTUM _IO(SCULL_IOC_MAGIC,  11)
#define SCULL_IOCHQSET    _IO(SCULL_IOC_MAGIC,  12)

/*
 * The other entities only have "Tell" and "Query", because they're
 * not printed in the book, and there's no need to have all six.
 * (The previous stuff was only there to show different ways to do it.
 */
#define SCULL_P_IOCTSIZE _IO(SCULL_IOC_MAGIC,   13)
#define SCULL_P_IOCQSIZE _IO(SCULL_IOC_MAGIC,   14)
/* ... more to come */

#define SCULL_IOCHARDRESET _IO(SCULL_IOC_MAGIC, 15) /* debugging tool */

#define SCULL_IOC_MAXNR 15

