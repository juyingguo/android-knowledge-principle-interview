#include <stdio.h>
#include <string.h>
 
int main()
{
   char src[40];
   char dest[0];
   
   //char *dest;
   
   char *result;
   
   //int i = 0;
//   for(i=0; i<100; i++){
//    	 printf("%d \n", dest[i]);
//    }
   
  
   //memset(dest, '\0', sizeof(dest));
	printf("当前dest字符串： %s\n", result);
   
   strcpy(src, "This is runoob.com. hello c");
   result = strcpy(dest, src);
 
   printf("最终的目标字符串： %s\n", dest);
	printf("返回值字符串： %s\n", result);
   
   return(0);
}
