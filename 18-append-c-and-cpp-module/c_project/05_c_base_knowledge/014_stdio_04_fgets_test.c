#include <stdio.h>

int main()
{
   FILE *fp;
   char str[60];

   /* �����ڶ�ȡ���ļ� */
   fp = fopen("file.txt" , "r");
   if(fp == NULL) {
      perror("���ļ�ʱ��������");
      return(-1);
   }
   if( fgets (str, 60, fp)!=NULL ) {
      /* ���׼��� stdout д������ */
      puts(str);
   }
   fclose(fp);
   
   return(0);
}
