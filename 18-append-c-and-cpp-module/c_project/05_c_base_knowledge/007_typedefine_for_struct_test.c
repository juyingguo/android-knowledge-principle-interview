#include <stdio.h>
#include <string.h>

typedef struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Books;//对于自定义类型，typedef定义类型名称可以和类型原名称相同。

int main( )
{
   Books book;

   strcpy( book.title, "C 教程");
   strcpy( book.author, "Runoob");
   strcpy( book.subject, "编程语言");
   book.book_id = 12345;

   printf( "书标题 : %s\n", book.title);
   printf( "书作者 : %s\n", book.author);
   printf( "书类目 : %s\n", book.subject);
   printf( "书 ID : %d\n", book.book_id);

   return 0;
}
