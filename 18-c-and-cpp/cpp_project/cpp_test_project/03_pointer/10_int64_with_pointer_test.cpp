#include <stdio.h>
#include <time.h>
 
void getSeconds(/*unsigned long*/ __int64 *par);

int main ()
{
   //unsigned long sec;
   //long long sec;
   
	__int64 sec;// ��Ϊ long long  

   getSeconds( &sec );//ֱ���޸���sec ��ֵ��

   /* ���ʵ��ֵ */
   printf("Number of seconds: %d\n", sec );

   return 0;
}

/**
ͨ������ָ�������������ֱ���޸�ԭ������ʵ�Σ�������������ʵ�ε��βΡ�
*/
void getSeconds(/*unsigned long*/ __int64 *par)
{
   /* ��ȡ��ǰ������ */
   *par = time( NULL );
   return;
}