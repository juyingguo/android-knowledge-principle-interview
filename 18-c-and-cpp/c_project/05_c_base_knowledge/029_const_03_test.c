/*
��ʽ��int * const pTmp
���壺pTmp�����޸ģ���pTmp��ָ��Ķ�������޸ġ�
*/
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i = 1;
  int j = 100;

  int * const pTmp = &i;
  printf("pTmp = %d\n", *pTmp);

  i = 2;
  printf("pTmp = %d\n", *pTmp);

  pTmp = &j;  /*����pTmp�����޸ģ�������ʾ��error:assignment of read-only variable `pTmp'*/
  printf("pTmp = %d\n", *pTmp);


  (*pTmp)++; /*��ȷ��pTmp��ָ��Ķ�������޸� */
  printf("pTmp = %d\n", *pTmp);

  system("PAUSE");

  return 0;
}
