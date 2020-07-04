/*
 * datasize.c -- print the size of common data items
 *
 * This runs with any Linux kernel (not any Unix, because of <linux/types.h>)
 */
#include <stdio.h>
#include <sys/utsname.h>
#include <linux/types.h>

int main(int argc, char **argv)
{
    struct utsname name;

    uname(&name); /* never fails :) */
    printf("arch   Size:  char  short  int  long   ptr long-long "
	   " u8 u16 u32 u64\n");
    printf(       "%-12s  %3i   %3i   %3i   %3i   %3i   %3i      "
	   "%3i %3i %3i %3i\n",
	   name.machine,
	   (int)sizeof(char), (int)sizeof(short), (int)sizeof(int),
	   (int)sizeof(long),
	   (int)sizeof(void *), (int)sizeof(long long), (int)sizeof(__u8),
	   (int)sizeof(__u16), (int)sizeof(__u32), (int)sizeof(__u64));
    return 0;
}
