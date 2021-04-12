#include <stdio.h>
#include <string.h>

int main()
{
   char str1[15];
   char str2[15];

   strcpy(str1, "RUNOOB1");
   strcpy(str2, "RUNOOB2");

   puts(str1);
   int ret = puts(str2);
   printf("puts(str2) reult :%d\n",ret);
   
   return(0);
}
