#include <stdio.h>
#include <stdlib.h>

int main()
{
   char str[30] = "2030305 This is test.";
   char *ptr;
   long ret;

   ret = strtoul(str, &ptr, 10);
   printf("���֣��޷��ų��������� %lu\n", ret);
   printf("�ַ��������� |%s|", ptr);

   return(0);
}
