/**
 *形式：int * const * pTmp
 *含义：pTmp可以修改，pTmp所指对象不能修改。
 * 该形式效果同{int const * pTmp}
 */
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i = 1;
  int j = 100;

  int *p = &j;

  int * const * pTmp = &i;
  printf("pTmp = %d\n", *pTmp);

  i = 2;  /*正确*/
  printf("pTmp = %d\n", *pTmp);

  pTmp = &j;//ok
  printf("pTmp = %d\n", *pTmp);


  (*pTmp)++;  /*错误：error: increment of read-only location*/
  printf("pTmp = %d\n", *pTmp);

  system("PAUSE");

  return 0;
}
