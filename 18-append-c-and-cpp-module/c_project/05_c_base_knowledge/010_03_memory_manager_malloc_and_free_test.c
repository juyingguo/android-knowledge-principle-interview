#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
   char name[100];
   char *description;
 
   strcpy(name, "Zara Ali");
 
   /* ��̬�����ڴ� */
   description = (char *)malloc( 20 * sizeof(char) );
   if( description == NULL )
   {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }
   else
   {
      strcpy( description, "Zara ali a student.");
   }
   /* ��������Ҫ�洢�����������Ϣ */
   //description = (char *) realloc( description, 40 * sizeof(char) );
   if( description == NULL )
   {
      fprintf(stderr, "Error - unable to realloc required memory\n");
   }
   else
   {
      strcat( description, "She is in class 2th");
   }
   
   printf("Name = %s\n", name );
   printf("Description: %s\n", description );
 
   /* ʹ�� free() �����ͷ��ڴ� */
   free(description);
   //system("pause");
   return 0;
}

