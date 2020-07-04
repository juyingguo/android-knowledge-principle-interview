/*
 * mapper.c -- simple file that mmap()s a file region and prints it
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
    void *address;

    if (argc !=4
       || sscanf(argv[2],"%i", &offset) != 1
       || sscanf(argv[3],"%i", &len) != 1) {
        fprintf(stderr, "%s: Usage \"%s <file> <offset> <len>\"\n", argv[0],
                argv[0]);
        exit(1);
    }
    fname=argv[1];

    if (!(f=fopen(fname,"r"))) {
        fprintf(stderr, "%s: %s: %s\n", argv[0], fname, strerror(errno));
        exit(1);
    }

    address=mmap(0, len, PROT_READ, MAP_FILE | MAP_PRIVATE, fileno(f), offset);

    if (address == (void *)-1) {
        fprintf(stderr,"%s: mmap(): %s\n",argv[0],strerror(errno));
        exit(1);
    }
    fclose(f);
    fprintf(stderr, "mapped \"%s\" from %i to %i\n",
            fname, offset, offset+len);

    fwrite(address, 1, len, stdout);
    return 0;
}
        
