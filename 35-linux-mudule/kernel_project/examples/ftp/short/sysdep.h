
/*
 * sysdep.h -- fixes some problems of portability in the range 1.2 - 2.0
 *
 * kdev_t                         for kernels < 1.3.28
 * do_gettimeofday                for kernels < 1.3.46
 * request_irq/free_irq/SA_SHIRQ  for kernels < 1.3.70
 * FMODE_READ/FMODE_WRITE         for kernels < 1.3.46
 * ioctl definitions              for kernels < 1.3.42
 * get_user/put_user              for kernels < 1.3.0
 * __*_ENDIAN                     for kernels < 1.3.19
 * put_unaligned etc              for kernels < 1.99.6
 * readb etc.                     for kernels < 1.3.4
 * add_timer                      fir kernels < 1.3.14
 * typing for count in read/write to account for differences in 2.1
 * typing for offset in lseek to account for differences in 2.1
 *
 *********/

#ifndef _ORABOOK_SYSDEP_H
#define _ORABOOK_SYSDEP_H

#ifndef VERSION_CODE
#  define VERSION_CODE(vers,rel,seq) ( ((vers)<<16) | ((rel)<<8) | (seq) )
#endif

#include <linux/sched.h> /* this is needed for functions I use here */

/*
 * Macros to fake kdev_t with old kernels
 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,28)
#  define kdev_t dev_t
   /* two conversion functions are defined in newer kernels */
#  define kdev_t_to_nr(dev) (dev)
#  define to_kdev_t(dev)    (dev)
#endif


/*
 * Reimplement do_gettimeofday (with less precision) for versions
 * not exporting the true code
 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,46)
/* 
 * kernel headers already declare the function as non-static.
 * We reimplement it with another name, and #define it
 */
extern inline void redo_gettimeofday(struct timeval *tv)
{
    unsigned long flags;

    save_flags(flags);
    cli();
    *tv = xtime;
    restore_flags(flags);
}
#define do_gettimeofday(tv) redo_gettimeofday(tv)
#endif


/*
 * 1.3.70 changed the semantics of irq request/free to allow shared irq's
 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,70)
   /* the preprocessor is able to handle recursive definitions */
#  define request_irq(irq,fun,fla,nam,dev) request_irq(irq,fun,fla,nam)
#  define free_irq(irq,dev)                free_irq(irq)
#  define SA_SHIRQ 0 /* doesn't exist */
#endif


/*
 * FMODE_READ was introduced in 1.3.46.
 * Explicit numbers were used before then
 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,46)
#  define FMODE_READ 1
#  define FMODE_WRITE 2
#endif


/*
 * 1.3.22 added the full featured ioctl bitmasks and macros
 *        but with _IOC_READ and _IOC_WRITE swapped.
 *        Earlier kernels defined some of them, but not all.
 *        Besides, macros in 1.2.x are really ugly to read.
 * 1.3.32 added _IOC_TYPE
 * 1.3.42 fixed _IOC_READ and _IOC_WRITE
 *
 * The errors are understandable in experimental kernels, but
 * try to fix them here. I, for one, still run 1.3.30 and 1.3.41,
 * which used to be very stable kernels. At the time no drivers used
 * such macros, so nobody noticed the were buggy. Since I uses them here,
 * I want them right.
 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,22)

#  define _IOC_NRBITS     8
#  define _IOC_TYPEBITS   8
#  define _IOC_SIZEBITS   14
#  define _IOC_DIRBITS    2

#  define _IOC_NRMASK     ((1 << _IOC_NRBITS)-1)
#  define _IOC_TYPEMASK   ((1 << _IOC_TYPEBITS)-1)
#  define _IOC_SIZEMASK   ((1 << _IOC_SIZEBITS)-1)
#  define _IOC_DIRMASK    ((1 << _IOC_DIRBITS)-1)

#  define _IOC_NRSHIFT    0
#  define _IOC_TYPESHIFT  (_IOC_NRSHIFT+_IOC_NRBITS)
#  define _IOC_SIZESHIFT  (_IOC_TYPESHIFT+_IOC_TYPEBITS)
#  define _IOC_DIRSHIFT   (_IOC_SIZESHIFT+_IOC_SIZEBITS)

#  define _IOC_DIR(nr)            (((nr) >> _IOC_DIRSHIFT) & _IOC_DIRMASK)
#  define _IOC_NR(nr)             (((nr) >> _IOC_NRSHIFT) & _IOC_NRMASK)
#  define _IOC_SIZE(nr)           (((nr) >> _IOC_SIZESHIFT) & _IOC_SIZEMASK)

#endif

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,32)
#  define _IOC_TYPE(nr)           (((nr) >> _IOC_TYPESHIFT) & _IOC_TYPEMASK)
#endif

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,42)
#  undef _IOC_NONE
#  undef _IOC_WRITE
#  undef _IOC_READ
#  define _IOC_NONE       0U
#  define _IOC_WRITE      1U
#  define _IOC_READ       2U
#endif


/*******************************************************************
 * 1.3.0 added the put_user size-independent macro. Copy it here
 *
 * This code (up to the next line of stars) comes from the kernel headers
 */
#if LINUX_VERSION_CODE < VERSION_CODE(1,3,0)


#define put_user(x,ptr) __put_user((unsigned long)(x),(ptr),sizeof(*(ptr)))
#define get_user(ptr) ((__typeof__(*(ptr)))__get_user((ptr),sizeof(*(ptr))))

/*
 * This is a silly but good way to make sure that
 * the __put_user function is indeed always optimized,
 * and that we use the correct sizes..
 */
extern int bad_user_access_length(void);

/*
 * dummy pointer type structure.. gcc won't try to do something strange
 * this way..
 */
struct __segment_dummy { unsigned long a[100]; };
#define __sd(x) ((struct __segment_dummy *) (x))
#define __const_sd(x) ((const struct __segment_dummy *) (x))

static inline void __put_user(unsigned long x, void * y, int size)
{
        switch (size) {
	case 1:
                        __asm__ ("movb %b1,%%fs:%0"
				 :"=m" (*__sd(y))
				 :"iq" ((unsigned char) x), "m" (*__sd(y)));
                        break;
			case 2:
                        __asm__ ("movw %w1,%%fs:%0"
				 :"=m" (*__sd(y))
				 :"ir" ((unsigned short) x), "m" (*__sd(y)));
                        break;
			case 4:
                        __asm__ ("movl %1,%%fs:%0"
				 :"=m" (*__sd(y))
				 :"ir" (x), "m" (*__sd(y)));
                        break;
			default:
                        bad_user_access_length();
			}
	}
static inline unsigned long __get_user(const void * y, int size)
{
        unsigned long result;

        switch (size) {
	case 1:
                        __asm__ ("movb %%fs:%1,%b0"
				 :"=q" (result)
				 :"m" (*__const_sd(y)));
                        return (unsigned char) result;
			case 2:
                        __asm__ ("movw %%fs:%1,%w0"
				 :"=r" (result)
				 :"m" (*__const_sd(y)));
                        return (unsigned short) result;
			case 4:
                        __asm__ ("movl %%fs:%1,%0"
				 :"=r" (result)
				 :"m" (*__const_sd(y)));
                        return result;
			default:
                        return bad_user_access_length();
			}
	}


/*******************************************************************/
#endif

/*
 * __LITTLE_ENDIAN and friends missed the underscore before 1.3.19
 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,19)
#  ifdef LITTLE_ENDIAN
#    define __LITTLE_ENDIAN
#    define __LITTLE_ENDIAN_BITFIELD
#  endif
#  ifdef BIG_ENDIAN
#    define __BIG_ENDIAN
#    define __BIG_ENDIAN_BITFIELD
#  endif
#endif


/*
 * get_unaligned was only incroduced in 1.99.6, but asm-generic
 * has a C reimplementation for it. Here it is (just copied :)
 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,99,6)
#  ifndef __i386__
#    include <asm/string.h> /* memcpy */
#    define get_unaligned(ptr)                             \
       ({ __typeof__(*(ptr)) __tmp;                        \
         memcpy(&__tmp, (ptr), sizeof(*(ptr))); __tmp; })
#    define put_unaligned(val, ptr)                        \
       ({ __typeof__(*(ptr)) __tmp = (val);                \
         memcpy((ptr), &__tmp, sizeof(*(ptr)));            \
         (void)0; })
#  else
#    define get_unaligned(ptr) (*(ptr))
#    define put_unaligned(val, ptr) ((void)( *(ptr) = (val) ))
#  endif /* i386 */
#endif

/*
 * define readb etc. This is only valid for the Intel platform
 */

#if LINUX_VERSION_CODE < VERSION_CODE(1,3,4)

#define readb(addr) (*(volatile unsigned char *) (addr))
#define readw(addr) (*(volatile unsigned short *) (addr))
#define readl(addr) (*(volatile unsigned int *) (addr))

#define writeb(b,addr) ((*(volatile unsigned char *) (addr)) = (b))
#define writew(b,addr) ((*(volatile unsigned short *) (addr)) = (b))
#define writel(b,addr) ((*(volatile unsigned int *) (addr)) = (b))

#define memset_io(a,b,c)        memset((void *)(a),(b),(c))
#define memcpy_fromio(a,b,c)    memcpy((a),(void *)(b),(c))
#define memcpy_toio(a,b,c)      memcpy((void *)(a),(b),(c))

#endif

/*
 * 2.1 (and the axp-diffs-2.0.x) changed from `int' to `unsigned long'
 * the count argument to read() and write(). Define a portable count_t
 */

#if defined(__alpha__) || (LINUX_VERSION_CODE >= VERSION_CODE(2,1,0))
# define count_t unsigned long
# define read_write_t long
#else
# define count_t int
# define read_write_t int
#endif


#if LINUX_VERSION_CODE < VERSION_CODE(1,3,14)
# define add_timer(t) do {(t)->expires-=jiffies; add_timer(t);} while(0)
#endif

#endif /* _ORABOOK_SYSDEP_H */
