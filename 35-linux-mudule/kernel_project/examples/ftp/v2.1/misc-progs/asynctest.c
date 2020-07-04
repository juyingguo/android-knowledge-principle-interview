/*
 * asynctest.c: use async notification to read stdin
 *
 * Tested with 1.2 on the x86
 * Tested with 2.0 on the x86, Sparc and Alpha
 *   (but pipes don't generate async signals, tty's do)
 *
 * Actually, it should run with any Unix
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

int gotdata=0;
void sighandler(int signo)
{
    signal(SIGIO, &sighandler); /* reinstall yourself */
    if (signo==SIGIO)
        gotdata++;
    return;
}

char buffer[4096];

int main(int argc, char **argv)
{
    int count;

    signal(SIGIO, &sighandler); /* the dirty way, sigaction() is better */
    fcntl(0, F_SETOWN, getpid());
    fcntl(0, F_SETFL, fcntl(0, F_GETFL) | FASYNC);

    while(1) {
        /* this only returns if a signal arrives */
        sleep(~0); /* infinite */
        if (!gotdata)
            continue;
        count=read(0, buffer, 4096);
        /* buggy: if avail data is more than 4kbytes... */
        write(1,buffer,count);
        gotdata=0;
    }
}
