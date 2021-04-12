#include <stdio.h>
 
#define .a int 
int main ()
{
   char a = 3;

   /* 输出实际值 */
   printf("Number of seconds: %d\n", a );
   printf("Number of seconds: %c\n", a );
   
   .a = 10;

   return 0;
}
