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
	printf("��ǰdest�ַ����� %s\n", result);
   
   strcpy(src, "This is runoob.com. hello c");
   result = strcpy(dest, src);
 
   printf("���յ�Ŀ���ַ����� %s\n", dest);
	printf("����ֵ�ַ����� %s\n", result);
   
   return(0);
}
