#include <stdio.h>

struct Book
{
   char  *title;
   char  author[50];
   char  subject[100];
   int   book_id;
};
static struct Book book =
{
   .title = "test designate struct.",
   .book_id = 101,
} ;

int main()
{
    printf("title : %s\n book_id: %d\n author: %s\n", book.title,book.book_id,book.author);
}
