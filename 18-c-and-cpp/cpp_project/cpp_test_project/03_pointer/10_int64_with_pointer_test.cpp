#include <stdio.h>
#include <time.h>
 
void getSeconds(/*unsigned long*/ __int64 *par);

int main ()
{
   //unsigned long sec;
   //long long sec;
   
	__int64 sec;// 即为 long long  

   getSeconds( &sec );//直接修改了sec 的值。

   /* 输出实际值 */
   printf("Number of seconds: %d\n", sec );

   return 0;
}

/**
通过传递指针给函数，可以直接修改原参数（实参），而不是引用实参到形参。
*/
void getSeconds(/*unsigned long*/ __int64 *par)
{
   /* 获取当前的秒数 */
   *par = time( NULL );
   return;
}