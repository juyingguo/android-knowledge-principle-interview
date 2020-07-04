/*
 * setlevel.c -- choose a console_loglevel for the kernel
 *
 * Tested with 2.0 2.2 2.4  on x86
 * Tested with 2.0          on SPARC
 * Tested with 2.0          on Alpha
 * Tested with     2.2      on ARM
 * Tested with     2.2      on PowerPC
 * Tested with     2.2      on SPARC64
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #include <unistd.h> */ /* conflicting on the alpha */
#define __LIBRARY__ /* _syscall3 and friends are only available through this */
#include <linux/unistd.h>

/* define the system call, to override the library function */
_syscall3(int, syslog, int, type, char *, bufp, int, len);

int main(int argc, char **argv)
{
    int level;

    if (argc==2) {
	level = atoi(argv[1]); /* the chosen console */
    } else {
        fprintf(stderr, "%s: need a single arg\n",argv[0]); exit(1);
    }
    if (syslog(8,NULL,level) < 0) {  
        fprintf(stderr,"%s: syslog(setlevel): %s\n",
                argv[0],strerror(errno));
        exit(1);
    }
    exit(0);
}
