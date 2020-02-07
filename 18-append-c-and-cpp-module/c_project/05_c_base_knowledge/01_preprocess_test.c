#include <stdio.h>

#define DEBUG 1 
#ifdef DEBUG
  #define SHOW_LOG 1
#endif
int main ()
{
   
   printf("TEST \n");
	printf("TEST ,%d \n" ,DEBUG);

   return 0;
}

