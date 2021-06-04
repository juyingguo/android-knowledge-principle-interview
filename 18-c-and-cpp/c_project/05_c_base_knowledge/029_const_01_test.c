#include <stdio.h>
int main(int argc, char *argv[])
{
  int i = 1;

  int  *pTmp = &i;
  printf("pTmp = %d\n", *pTmp);

  i = 2;
  printf("pTmp = %d\n", *pTmp);

  (*pTmp)++;
  printf("pTmp = %d\n", *pTmp);

  system("PAUSE");

  return 0;
}
