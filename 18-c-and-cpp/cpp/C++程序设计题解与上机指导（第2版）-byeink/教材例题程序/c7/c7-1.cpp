#include <iostream>
using namespace std;
struct Date
  {int month;
   int day;
   int year;
  };
 struct Student
  {int num;
   char name[20];
   char sex;
   Date birthday;
   float score;
  }student1,student2={10002,"Wang Li",'f',5,23,1982,89.5};

int main()
{student1=student2;
 cout<<student1.num<<endl;
 cout<<student1.name<<endl;
 cout<<student1.sex<<endl;
 cout<<student1.birthday.month<<'/'<<student1.birthday.day<<'/';
 cout<<student1.birthday.year<<endl;
 cout<<student1.score<<endl;
 return 0;
}
