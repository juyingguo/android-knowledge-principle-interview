#include <stdio.h>
/*
#define STATE \ 
	state_flag \
	//
*/
#define  SENSORS_LIST  \
    SENSOR_(ACCELERATION,"acceleration") \
    //
int main(void)
{
   //printf("STATE =  %d\n", STATE);  
   printf("SENSORS_LIST =  %d\n", SENSORS_LIST);  
   return 0;
}
