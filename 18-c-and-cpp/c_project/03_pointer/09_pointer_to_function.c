#include <stdio.h>
#include <time.h>
 
void getSeconds(/*unsigned long*/ __int64 *par);

int main ()
{
   //unsigned long sec;
   __int64 sec;


   getSeconds( &sec );

   /* ���ʵ��ֵ */
   printf("Number of seconds: %d\n", sec );

   return 0;
}

void getSeconds(/*unsigned long*/ __int64 *par)
{
   /* ��ȡ��ǰ������ */
   *par = time( NULL );
   return;
}
