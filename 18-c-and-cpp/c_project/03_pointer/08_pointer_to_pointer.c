#include <stdio.h>
 
int main ()
{
   int  var;
   int  *ptr;
   int  **pptr;
   int  ***ppptr;

   var = 3000;

   /* ��ȡ var �ĵ�ַ */
   ptr = &var;

   /* ʹ������� & ��ȡ ptr �ĵ�ַ */
   pptr = &ptr;
   
   ppptr = &pptr;

   /* ʹ�� pptr ��ȡֵ */
   printf("Value of var = %d\n", var ); 
   printf("Value available at *ptr = %d\n", *ptr );
   printf("Value available at **pptr = %d\n", **pptr);
   
   printf("Value available at ***ppptr = %d\n", ***ppptr);

   return 0;
}
