#include <stdio.h>
 
int main ()
{
   int n[ 10 ]; /* n ��һ������ 10 ������������ */
   int i,j;
 
   /* ��ʼ������Ԫ�� */         
   for ( i = 0; i < 10; i++ )
   {
      n[ i ] = i + 100; /* ����Ԫ�� i Ϊ i + 100 */
   }
   
   /* ���������ÿ��Ԫ�ص�ֵ */
   for (j = 0; j < 10; j++ )
   {
      printf("Element[%d] = %d\n", j, n[j] );
   }
 
   return 0;
}
