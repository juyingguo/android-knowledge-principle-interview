 #include <stdio.h>
 
const int MAX = 3;
 
int main ()
{
   int  var[] = {10, 100, 200};
   int  i, *ptr[MAX];
 
   for(i =0; i<MAX;i++){
   	
   	ptr[i] = &var[i];
   	
   }
    for(i =0; i<MAX;i++){
   	
   	 printf(" value of var[ %d ] = %d \n",i,ptr[i]) ;
   	
   }
   
   const char *names[] = {
                   "Zara Ali",
                   "Hina Ali",
                   "Nuha Ali"
   };
   for(i =0; i<MAX;i++){
   	
   	 printf(" value of names[ %d ] = %s \n",i,names[i]) ;
   	
   }
   
   char *px = "hell c.";
   
    printf(" value of px = %s \n",px) ;
   return 0;
}
