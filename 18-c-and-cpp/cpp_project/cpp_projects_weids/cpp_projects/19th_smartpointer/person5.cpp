
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person {

public:

	Person() {
		cout <<"Pserson()"<<endl;
	}


	~Person()
	{
		cout << "~Person()"<<endl;
	}
	void printInfo(void)
	{
		cout<<"just a test function"<<endl;
	}
};

class sp {
private:
	Person *p;

public:
	sp() : p(0) {}

	sp(Person *other)
	{
		cout<<"sp(Person *other)"<<endl;
		p = other;
	}

	sp(const sp &other)
	{
		cout<<"sp(const sp &other)"<<endl;
		p = other.p;
	}

	~sp()
	{
		cout<<"~sp()"<<endl;
		if (p)
			delete p;
	}

	Person *operator->()
	{
		return p;
	}

};

void test_func(sp &other)
{
	sp s = other;//��һ�ν���ú�����������ʱ��s�е�p��delete��person�������١��ڶ��ν����s�е�pָ���personΪnull.

	s->printInfo();

	//Person *p = new Person();
	//p->printInfo();
	//delete p;


}

int main(int argc, char **argv)
{
	int i;

	sp other = new Person();
//	sp other = NULL;//ͬ������ù��캯��

	for (i = 0; i < 1; i++)
		test_func(other);
	return 0;
}

