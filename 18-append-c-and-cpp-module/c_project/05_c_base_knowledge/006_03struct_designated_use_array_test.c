#include <stdio.h>

struct Book
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};
static struct Book book =  
{
   .title = "test designate struct. use array",
   .book_id = 101,
} ;
 
int main()
{
    printf("title : %s\n book_id: %d\n", book.title,book.book_id);
}
