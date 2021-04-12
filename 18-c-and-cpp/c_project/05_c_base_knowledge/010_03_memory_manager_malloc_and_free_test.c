#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
   char name[100];
   char *description;
 
   strcpy(name, "Zara Ali");
 
   /* 动态分配内存 */
   description = (char *)malloc( 20 * sizeof(char) );
   if( description == NULL )
   {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }
   else
   {
      strcpy( description, "Zara ali a student.");
   }
   /* 假设您想要存储更大的描述信息 */
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
 
   /* 使用 free() 函数释放内存 */
   free(description);
   //system("pause");
   return 0;
}

