#include <stdio.h>
#include <string.h>
struct Book
{
   char  *title;
   char  *description;
   int   book_id;
   int price:10;
};

 
int main()
{
 	struct Book book ={
	 	title:"c program language.",
	 	book_id:202
	 	
	 };
	struct Book book_two;
 	//strcpy(book.title,"");
	
    printf("title : %s\n book_id: %d\n  price:%d\n ", book.title,book.book_id,book.price);
    printf("title : %s\n book_id: %d\n  price:%d\n ", book_two.title,book_two.book_id,book_two.price);
}
