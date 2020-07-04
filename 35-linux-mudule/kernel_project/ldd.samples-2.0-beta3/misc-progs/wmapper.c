/*
 * wmapper.c -- simple file that mmap()s a file region and writes to it
 *
 * Tested with 2.0 2.2 2.4  on x86
 * Tested with 2.0          on SPARC
 * Tested with 2.0          on Alpha
 * Tested with     2.2      on ARM
 * Tested with     2.2      on PowerPC
 * Tested with     2.2      on SPARC64
 *
 * Actually, it should run with any Unix
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>

int main(int argc, char **argv)
{
    char *fname;
    FILE *f;
    unsigned int offset, len;
    unsigned char *address;
    int i, c;

    if (argc !=4
       || sscanf(argv[2],"%i", &offset) != 1
       || sscanf(argv[3],"%i", &len) != 1) {
        fprintf(stderr, "%s: Usage \"%s <file> <offset> <len>\"\n", argv[0],
                argv[0]);
        exit(1);
    }
    fname=argv[1];

    if (!(f=fopen(fname,"r+"))) {
        fprintf(stderr, "%s: %s: %s\n", argv[0], fname, strerror(errno));
        exit(1);
    }

    address=mmap(0, len, PROT_READ | PROT_WRITE,
		 MAP_FILE | MAP_SHARED, fileno(f), offset);

    if (address == (void *)-1) {
        fprintf(stderr,"%s: mmap(): %s\n",argv[0],strerror(errno));
        exit(1);
    }
    fclose(f);
    for (i=0; i<len; i++) {
        c = getchar();
        if (c==-1)
            return 0;
        address[i]=c;
    }
    return 0;
}
        
