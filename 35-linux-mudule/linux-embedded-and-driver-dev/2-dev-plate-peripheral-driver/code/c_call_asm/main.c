#include <stdio.h>

extern int myadd(int a, int b);

int main(void)
{
	int a = 3;
	int b = 5;
	int c;
	c = myadd(a, b);
	printf("%d\n", c);
	
	return 0;
}