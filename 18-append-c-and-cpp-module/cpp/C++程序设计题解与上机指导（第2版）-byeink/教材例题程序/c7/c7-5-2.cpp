#include <iostream>
#include <string>
using namespace std;
struct Student
{int num;
 string name;
 float score[3];
}stu={12345,"Li Fung",67.5,89,78.5};

int main()
{void print(Student *);
 Student *pt=&stu;
 print(pt);
 return 0;
}

void print(Student *p)
{cout<<p->num<<" "<<p->name<<" "<<p->score[0]<<" "
     <<p->score[1]<<" "<<p->score[2]<<endl;
}
