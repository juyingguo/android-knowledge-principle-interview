#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

int main()
{
   char *str;

   /* ������ڴ���� */
   str = (char *) malloc(1);
   strcpy(str, "runoobrunoobrunoob");//Ϊɶ����һ���ֽڣ�������д�����ֽڵ������أ�
   printf("String = %s,  Address = %u\n", str, str);
   printf("String = %s,  Address = %d\n", str, str);

   /* ���·����ڴ� */
//   str = (char *) realloc(str, 1);
//   strcat(str, ".com");
//   printf("String = %s,  Address = %u\n", str, str);

   free(str);

   return(0);
}
