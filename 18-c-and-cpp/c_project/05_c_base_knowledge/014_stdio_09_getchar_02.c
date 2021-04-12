#include <stdio.h>

int main(void)
{
   int c;

   /* Note that getchar reads from stdin and
      is line buffered; this means it will
      not return until you press ENTER. */
    int i = 0;
   while ((c = getchar()) != '0'){
      printf("%c", c);
        i++;
        printf("i=%d\n",i);
   }

   return 0;
}

