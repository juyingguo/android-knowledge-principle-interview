#include <stdio.h>

#define MAX(x,y) ((x) > (y) ? (x) : (y))

#define square(x) ((x) * (x))

int main(void)
{
   printf("Max between 20 and 10 is %d\n", MAX(50000, 20));


   printf("square(%d) == %d\n", 5,square(50));

   return 0;
}
