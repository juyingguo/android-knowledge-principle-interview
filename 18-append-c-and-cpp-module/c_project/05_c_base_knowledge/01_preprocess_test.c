#include <stdio.h>

#define DEBUG 1 
#ifdef DEBUG
  #define SHOW_LOG 1
#endif

#define  message_for(a, b)  \
    printf(#a " and " #b ": We love you!\n");
int main ()
{
   
   printf("TEST \n");
	printf("TEST ,%d \n" ,DEBUG);
	
	printf("sizeof(char) %d\n",sizeof(char));
	
	message_for(Carole, Debra) //�����ټӷֺ��ˣ��궨���м��˷ֺš� 
   return 0;
}

