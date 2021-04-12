#include <stdio.h>
#include <string.h>

int main ()
{
   char str1[12] = "Hello";//同于"Hello\0"
   char str2[12] = "World";
   char str3[12];
   int  len ;

   printf("strlen(str1) :  %d\n", strlen(str1) );

   /* 复制 str1 到 str3 */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );

   printf("strlen(str3) :  %d\n", strlen(str3) );

   /* 连接 str1 和 str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );

   /* 连接后，str1 的总长度 */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );


    char str4[10] = "test\n";
    printf("strlen(str4) :  %d\n", strlen(str4) );
   return 0;
}
