#include <iostream>
#include <string>
using namespace std;
class Student
{public:
  void display( )
    {cout<<"num: "<<num<<endl;
     cout<<"name: "<<name<<endl;
     cout<<"sex: "<<sex<<endl;}
 private :
   int num;
   string name;
   char sex;
};   

class Student1: private Student
 {public:
   void display_1()
       {display();
       cout<<"age: "<<age<<endl;          //�����������˽�г�Ա����ȷ
       cout<<"address: "<<addr<<endl;}    //�����������˽�г�Ա����ȷ
  private:
       int age;
       string addr;
 };
 
int main()
 {Student1 stud1;
  stud1.display_1();
  return 0;
} 
