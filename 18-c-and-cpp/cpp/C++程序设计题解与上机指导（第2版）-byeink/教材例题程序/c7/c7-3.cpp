#include <iostream>
#include <string>
using namespace std;
int main()
 {struct student
   {int num;
    string name;
    char sex;
    float score;
 };
 student stu;
 student *p=&stu;
 stu.num=10301;
 stu.name="Wang Fun";
 stu.sex='f';
 stu.score=89.5;
 cout<<stu.num<<" "<<stu.name<<" "<<stu.sex<<" "<<stu.score<<endl;
 cout<<(*p).num<<" "<<(*p).name<<" "<<(*p).sex<<" "<<(*p).score<<endl;
 return 0;
}