#include <stdio.h>
#include <string.h>
 
union Data
{
   int i;
   float f;
   double d; 
   char  str[2];
}; 
 
int main( )
{
   union Data data;        
 
   printf( "Memory size occupied by data : %d\n", sizeof(data));
 
   return 0;
}
