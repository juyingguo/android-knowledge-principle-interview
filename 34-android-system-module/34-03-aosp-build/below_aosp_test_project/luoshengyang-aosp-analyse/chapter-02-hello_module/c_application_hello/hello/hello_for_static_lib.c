#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int main(int argc, char** argv)
{
	int a = 100;
	int b = 50;
	int add = a+b;
	printf("a = %d,b = %d.\n", a,b);
	
	printf("a+ b = %d.\n", add);
	
	return add;
}
