
#include <stdio.h>

class Person {
private:
	char *name;
	int age;
	char *work = nullptr;

public:
	void setName(char *name);
	int setAge(int age);
	void setWork(char * work);
	void printInfo(void);
};

