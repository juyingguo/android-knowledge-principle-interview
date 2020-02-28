#include <stdio.h> 
#include <string.h> 
int main(void) 
{ 
   char src[] = "******************************"; 
   char dest[] = "abcdefghijlkmnopqrstuvwxyz0123456709"; 
   char *ptr; 
   printf("destination before memcpy: %s\n", dest); 
   ptr = memcpy(dest, src, strlen(src)); 
   if (ptr) 
      printf("destination after memcpy:  %s\n", dest); 
   else 
      printf("memcpy failed\n"); 
   return 0; 
} 
