/*
形式：int * const pTmp
含义：pTmp不可修改，但pTmp所指向的对象可以修改。
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

  pTmp = &j;  /*错误，pTmp不可修改，编译提示：error:assignment of read-only variable `pTmp'*/
  printf("pTmp = %d\n", *pTmp);


  (*pTmp)++; /*正确，pTmp所指向的对象可以修改 */
  printf("pTmp = %d\n", *pTmp);

  system("PAUSE");

  return 0;
}
