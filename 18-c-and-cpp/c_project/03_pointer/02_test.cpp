#include <stdio.h>
 
int main ()
{

	printf("************** pointer test start *****************\n");
  
   int  *ip = NULL;        
   /* 在指针变量中存储的地址 */
   printf("Address stored in ip variable: %p\n", ip );
   
   if(!ip){
   	printf("Address stored in ip variable: 0 can not use \n");
   }else{
   	printf("Address stored in ip variable: can use \n");
   }
   printf("************** pointer test end *****************\n");
   
   printf("************** exponent test start *****************\n");
   int a  = 12E-1L;
   printf("a = %d \n",a);
   
    int b  = 12E1;
   printf("b = %d \n",b);
   
     int c  = 2.5E1;
   printf("c = %d \n",c);
   
     float d  = 2.2e-1f;
   printf("d = %f \n",d);
    printf("************** exponent test end *****************\n");
    
    float fn = 3.5f;
    printf("fn = %.2f \n",fn);
   
   return 0;
}
