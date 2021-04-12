#include <stdio.h>
 
struct
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book = {"C ”Ô—‘", "RUNOOB", "±‡≥Ã”Ô—‘", 456};
 
int main()
{
    printf("title : %s\nauthor: %s\nsubject: %s\nbook_id: %d\n", book.title, book.author, book.subject, book.book_id);
}
