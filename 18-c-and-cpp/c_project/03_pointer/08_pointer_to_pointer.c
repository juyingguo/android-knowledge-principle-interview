#include <stdio.h>
 
int main ()
{
   int  var;
   int  *ptr;
   int  **pptr;
   int  ***ppptr;

   var = 3000;

   /* 获取 var 的地址 */
   ptr = &var;

   /* 使用运算符 & 获取 ptr 的地址 */
   pptr = &ptr;
   
   ppptr = &pptr;

   /* 使用 pptr 获取值 */
   printf("Value of var = %d\n", var ); 
   printf("Value available at *ptr = %d\n", *ptr );
   printf("Value available at **pptr = %d\n", **pptr);
   
   printf("Value available at ***ppptr = %d\n", ***ppptr);

   return 0;
}
