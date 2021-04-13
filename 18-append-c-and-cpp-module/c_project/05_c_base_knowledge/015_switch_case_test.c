#include <stdio.h>

int main ()
{
	int n = 2;
	switch(n){
		case 1:
			 printf("TEST %d\n",n);
			 //n = 2;
		case 2:
			 	 printf("TEST 2 %d\n",n);
//			 break;
		case 3:
			 	 printf("TEST 3 %d\n",n);
//			break;
        default:

			 	 printf("TEST default %d\n",n);
            break;
	}


   return 0;
}

