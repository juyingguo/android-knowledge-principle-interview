#include <iostream>
#include <string>
using namespace std;
struct Student
{int num;
 string name;
 float score[3];
};
int main()
{void print(Student);
 Student stu;
 stu.num=12345;
 stu.name="Li Fung";
 stu.score[0]=67.5;
 stu.score[1]=89;
 stu.score[2]=78.5;
 print(stu);
 return 0;
}

void print(Student stu)
{cout<<stu.num<<" "<<stu.name<<" "<<stu.score[0]<<" "
     <<stu.score[1]<<" "<<stu.score[2]<<endl;
}