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
static struct Book *book_sec[1];
int main()
{
    //book_sec[0] = &book;
    printf("title : %s\n book_id: %d\n author: %s\n", book.title,book.book_id,book.author);
    if(book_sec ==NULL){
         printf("book_sec == NULL\n");
    }
    printf("book_sec.author:%s \n",book_sec[0]->author);
}
