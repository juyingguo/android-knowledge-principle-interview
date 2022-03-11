
#include <stdio.h>

int main(int argc, char **argv)
{
	char *names[] = {"zhangsan", "lisi"};
	char ages[] = {10, 16};
	char *work[] = {"teacher", "doctor"};

	int i;

	for (i = 0; i < 2; i++)
	{
		printf("name = %s, age = %d, work = %s\n", names[i], ages[i],work[i]);
		printf("name = %s, age = %d, work = %s\n", names[i], ages[i],*(work+i));
	}

	return 0;
}

