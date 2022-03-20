/*
形式：const int *pTmp

含义：表示pTmp所指向的对象是只读的，但pTmp可指向其他地址，即pTmp可变。

同：形式：int const *pTmp 同 const int *pTmp
*/
#include <stdio.h>
int main(int argc, char *argv[])
{
  int i = 1;
  int j = 100;

  const int  *pTmp = &i; /*正确：表示pTmp所指向的对象是只读的，但pTmp可指向其他地址，即pTmp可变*/
  printf("pTmp = %d\n", *pTmp);

  i = 3;
  printf("pTmp = %d\n", *pTmp);

  pTmp = &j;            /*正确：将pTmp指向变量j的地址*/
  printf("pTmp = %d\n", *pTmp);

//  (*pTmp)++; /*错误,pTmp指向的对象是只读的，编译出错提示：assignment of read-only location */
  printf("pTmp = %d\n", *pTmp);

  system("PAUSE");

  return 0;
}
