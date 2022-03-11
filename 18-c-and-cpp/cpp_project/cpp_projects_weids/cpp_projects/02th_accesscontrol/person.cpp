
#include <stdio.h>

class Person {
private:
	char *name = nullptr;
	int age = 0;
	char *work = nullptr;

public:
	void setName(char *n)
	{
		name = n;
	}
	int setAge(int a)
	{
		if (a < 0 || a > 150)
		{
			age = 0;
			return -1;
		}
		age = a;
		return 0;
	}
	void printInfo(void)
	{
		printf("name = %s, age = %d, work = %s\n", name, age, work);
	}
};

int main(int argc, char **argv)
{
	Person per;

	//per.name = "zhangsan";
	per.setName("zhangsan");
	per.setAge(200);
	per.printInfo();

	return 0;
}

