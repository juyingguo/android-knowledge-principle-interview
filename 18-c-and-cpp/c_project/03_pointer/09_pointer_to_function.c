#include <stdio.h>
#include <time.h>
 
void getSeconds(/*unsigned long*/ __int64 *par);

int main ()
{
   //unsigned long sec;
   __int64 sec;


   getSeconds( &sec );

   /* 输出实际值 */
   printf("Number of seconds: %d\n", sec );

   return 0;
}

void getSeconds(/*unsigned long*/ __int64 *par)
{
   /* 获取当前的秒数 */
   *par = time( NULL );
   return;
}
