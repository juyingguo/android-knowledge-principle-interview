#include <stdio.h>

int main ()
{
   int n[ 10 ]; /* n 是一个包含 10 个整数的数组 */
   int i,j;

   n[-2] = 10;

   /* 初始化数组元素 */
   for ( i = -2; i < 3; i++ )
   {
      n[ i ] = i + 100; /* 设置元素 i 为 i + 100 */
   }
//    printf("Element[%d] = %d\n", -1, n[-1] );
   /* 输出数组中每个元素的值 */
   for (j = -2; j < 3; j++ )
   {
      printf("Element[%d] = %d\n", j, n[j] );
   }

   return 0;
}
