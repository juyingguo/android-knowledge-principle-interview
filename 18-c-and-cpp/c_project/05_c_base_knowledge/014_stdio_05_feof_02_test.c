/*
1.采用另一种方式读取数据
*/
#include <stdio.h>

int main ()
{
   FILE *fp;
   int c;

   fp = fopen("file.txt","r");
   if(fp == NULL)
   {
      perror("打开文件时发生错误");
      return(-1);
   }
    int i = 0;
    c = fgetc(fp);

    printf("feof()=%d\n",feof(fp));
   while(!feof(fp))
   {
        i++;
        printf("i = %d,c = %c\n",i, c);
        c = fgetc(fp);

        printf("feof()=%d\n",feof(fp));

   }
   fclose(fp);
   return(0);
}
