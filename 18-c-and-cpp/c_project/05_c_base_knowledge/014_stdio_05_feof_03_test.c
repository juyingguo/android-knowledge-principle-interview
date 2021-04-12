/*
c�����ٲ�:
������: feof
��  ��: ������ϵ��ļ�������
��  ��: int feof(FILE *stream);

*/

#include <stdio.h>

int main(void)
{
   FILE *stream;

   /* open a file for reading */
   stream = fopen("file.txt", "r");

   /* read a character from the file */
   fgetc(stream);

   /* check for EOF */
   if (feof(stream))
      printf("We have reached end-of-file\n");

   /* close the file */
   fclose(stream);
   return 0;
}
