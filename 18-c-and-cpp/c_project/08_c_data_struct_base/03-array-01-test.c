#include <stdio.h>

int main ()
{
   int n[ 10 ]; /* n ��һ������ 10 ������������ */
   int i,j;

   n[-2] = 10;

   /* ��ʼ������Ԫ�� */
   for ( i = -2; i < 3; i++ )
   {
      n[ i ] = i + 100; /* ����Ԫ�� i Ϊ i + 100 */
   }
//    printf("Element[%d] = %d\n", -1, n[-1] );
   /* ���������ÿ��Ԫ�ص�ֵ */
   for (j = -2; j < 3; j++ )
   {
      printf("Element[%d] = %d\n", j, n[j] );
   }

   return 0;
}
