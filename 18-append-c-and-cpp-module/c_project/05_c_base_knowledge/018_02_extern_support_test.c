#include <stdio.h>

extern int count =20;

void write_extern(void)
{
   printf("count is %d\n", count);
}
