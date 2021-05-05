#include <stdio.h>

extern int fun(int a, int b);
int add(int a, int b)
{
	return a+b;
}
int main(void)
{
	int res;
	int a = 3, b = 5;
	res = fun(a, b);
	printf("%d\n", res);
	return 0;
	
}