#include <stdio.h>
#include "018_02_extern_support_test.c"
int count ;
extern void write_extern();
 
int main()
{
  
   write_extern();
    count = 5;
}
