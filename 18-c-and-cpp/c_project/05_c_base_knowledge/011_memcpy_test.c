/***
https://www.runoob.com/cprogramming/c-standard-library-string-h.html
https://www.runoob.com/cprogramming/c-function-memcpy.html
*/
#include <stdio.h>
#include <string.h>
int main(void)
{
   char src[] = "******************************";
   char dest[] = "abcdefghijlkmnopqrstuvwxyz0123456709";
   char *ptr;
   printf("destination before memcpy: %s\n", dest);
   printf("src length: %d\n", strlen(src));
   ptr = memcpy(dest, src, strlen(src));
   if (ptr)
      printf("destination after memcpy:  %s\n", dest);
   else
      printf("memcpy failed\n");
   return 0;
}
