#include<stdio.h>
 
int main ()
{
   FILE *fp;
   char str[] = "This is runoob.com";
 
   fp = fopen( "file.txt" , "w" );
   int n = fwrite(&str, sizeof(str) , 1, fp );
	printf("n = %d\n",n);
   fclose(fp);
  
   return(0);
}
