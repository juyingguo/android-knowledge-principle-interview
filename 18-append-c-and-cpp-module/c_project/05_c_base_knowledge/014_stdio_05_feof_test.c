#include <stdio.h>

int main ()
{
   FILE *fp;
   int c;

   fp = fopen("file.txt","r");
   if(fp == NULL)
   {
      perror("���ļ�ʱ��������");
      return(-1);
   }
   while(1)
   {
      c = fgetc(fp);
         printf("feof()=%d\n",feof(fp));
      if( feof(fp) )
      {
          break ;
      }
      printf("%c\n", c);
   }
   fclose(fp);
   return(0);
}
