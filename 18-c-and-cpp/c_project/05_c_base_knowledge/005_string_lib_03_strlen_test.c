#include <stdio.h>
#include <string.h>

int main ()
{
   char str1[12] = "Hello";//ͬ��"Hello\0"
   char str2[12] = "World";
   char str3[12];
   int  len ;

   printf("strlen(str1) :  %d\n", strlen(str1) );

   /* ���� str1 �� str3 */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );

   printf("strlen(str3) :  %d\n", strlen(str3) );

   /* ���� str1 �� str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );

   /* ���Ӻ�str1 ���ܳ��� */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );


    char str4[10] = "test\n";
    printf("strlen(str4) :  %d\n", strlen(str4) );
   return 0;
}
