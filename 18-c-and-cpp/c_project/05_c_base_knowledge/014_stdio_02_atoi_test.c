#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int val;
   char str[20];
   
   strcpy(str, "10");
   val = atoi(str);
   printf("�ַ���ֵ = %s, ����ֵ = %d\n", str, val);

   strcpy(str, "runoob.com");
   val = atoi(str);
   printf("�ַ���ֵ = %s, ����ֵ = %d\n", str, val);

   return(0);
}
