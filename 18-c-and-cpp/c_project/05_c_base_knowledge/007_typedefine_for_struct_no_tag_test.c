#include <stdio.h>
#include <string.h>
 
typedef struct
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Book;
 
int main( )
{
   Book book;
 
   strcpy( book.title, "C book");
   strcpy( book.author, "Runoob"); 
   strcpy( book.subject, "programing language");
   book.book_id = 12345;
 
   printf( "����� : %s\n", book.title);
   printf( "������ : %s\n", book.author);
   printf( "����Ŀ : %s\n", book.subject);
   printf( "�� ID : %d\n", book.book_id);
 
   return 0;
}
