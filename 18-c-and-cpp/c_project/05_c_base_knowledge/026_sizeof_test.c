#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
   char *str;

   /* 最初的内存分配 */
   str = (char *) malloc(1);
   strcpy(str, "runoob");
   printf("String = %s,  Address = %u\n", str, str);
   printf("String = %s,  Address = %d\n", str, str);

   printf("sizeof(char) = %d\n.",sizeof(char));
   printf("sizeof(*str) = %d\n.",sizeof(*str));
   printf("sizeof(str) = %d\n.",sizeof(str));

//   int *n = {4,5,6,7,8};
   int *n = {4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
   printf("sizeof(int) = %d\n.",sizeof(int));
   printf("sizeof(*n) = %d\n.",sizeof(*n));
   printf("sizeof(n) = %d\n.",sizeof(n));
    printf("******************\n");

    unsigned iodata[512/4];
    printf("sizeof(iodata) = %d\n.",sizeof(iodata));

   free(str);

   return(0);
}
