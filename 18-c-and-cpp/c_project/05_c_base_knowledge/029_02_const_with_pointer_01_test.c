/**
 形式：const int * const pTmp

 含义：pTmp不可修改，pTmp所指对象也不能修改。
*/
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i = 1;
  int j = 100;

  const int * const pTmp = &i;
  printf("pTmp = %d\n", *pTmp);

  i = 2;  /*正确*/
  printf("pTmp = %d\n", *pTmp);

  pTmp = &j;  /*错误：error: assignment of read-only variable `pTmp'*/
  printf("pTmp = %d\n", *pTmp);


  (*pTmp)++;  /*错误：error: increment of read-only location*/
  printf("pTmp = %d\n", *pTmp);

  system("PAUSE");

  return 0;
}