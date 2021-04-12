#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int main()
{
   char *str;

   /* 最初的内存分配 */
   str = (char *) malloc(1);
   strcpy(str, "runoobrunoobrunoob");//为啥分配一个字节，但可以写入多个字节的数据呢？
   printf("String = %s,  Address = %u\n", str, str);
   printf("String = %s,  Address = %d\n", str, str);

   /* 重新分配内存 */
//   str = (char *) realloc(str, 1);
//   strcat(str, ".com");
//   printf("String = %s,  Address = %u\n", str, str);

   free(str);

   return(0);
}
