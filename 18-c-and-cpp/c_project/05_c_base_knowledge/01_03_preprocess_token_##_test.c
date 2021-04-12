#include <stdio.h>

#define token34  50
#define tokenpaster(n) printf ("token" #n " = %d", token##n)

int main(void)
{
   //int token34 = 40;

   tokenpaster(34);
   return 0;
}
