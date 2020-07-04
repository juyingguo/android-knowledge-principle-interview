/*
 * datasize.c -- print the size of common data items
 *
 * Obviously, this run with any kernel and any Unix
 */
#include <stdio.h>
#include <sys/utsname.h>

int main(int argc, char **argv)
{
    struct utsname name;

    uname(&name); /* never fails :) */
    printf("system/machine: %s %s\n",name.sysname,name.machine);
    printf("sizeof(char) =     %i\n",(int)sizeof(char));
    printf("sizeof(short) =    %i\n",(int)sizeof(short));
    printf("sizeof(int) =      %i\n",(int)sizeof(int));
    printf("sizeof(long) =     %i\n",(int)sizeof(long));
    printf("sizeof(longlong) = %i\n",(int)sizeof(long long));
    printf("sizeof(pointer) =  %i\n",(int)sizeof(void *));
    return 0;
}
