/*
��ʽ��const int *pTmp

���壺��ʾpTmp��ָ��Ķ�����ֻ���ģ���pTmp��ָ��������ַ����pTmp�ɱ䡣

ͬ����ʽ��int const *pTmp ͬ const int *pTmp
*/
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i = 1;
  int j = 100;

  const int  *pTmp = &i; /*��ȷ����ʾpTmp��ָ��Ķ�����ֻ���ģ���pTmp��ָ��������ַ����pTmp�ɱ�*/
  printf("pTmp = %d\n", *pTmp);

  i = 3;
  printf("pTmp = %d\n", *pTmp);

  pTmp = &j;            /*��ȷ����pTmpָ�����j�ĵ�ַ*/
  printf("pTmp = %d\n", *pTmp);

//  (*pTmp)++; /*����,pTmpָ��Ķ�����ֻ���ģ����������ʾ��assignment of read-only location */
  printf("pTmp = %d\n", *pTmp);

  system("PAUSE");

  return 0;
}
