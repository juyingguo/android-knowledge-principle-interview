#include <stdio.h>



#define DEBUG

#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n");
int main ()
{
   
   printf("TEST \n");
   int a = 3;
   #ifdef DEBUG
	printf("TEST ,%d \n" ,a);
	#endif
	
	printf("sizeof(char) %ld\n",sizeof(char));
	
	message_for(Carole, Debra)
   return 0;
}

