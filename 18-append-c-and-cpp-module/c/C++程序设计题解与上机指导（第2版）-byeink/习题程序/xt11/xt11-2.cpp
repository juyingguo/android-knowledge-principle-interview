#include <iostream>
using namespace std;
class Student
{public:
  void get_value()
   {cin>>num>>name>>sex;}
  void display( )
    {cout<<"num: "<<num<<endl;
     cout<<"name: "<<name<<endl;
     cout<<"sex: "<<sex<<endl;}
 private :
   int num;
   char name[10];
   char sex;
};   

class Student1: private Student
 {public:
   void get_value_1()
    {get_value();
     cin>>age>>addr;}
   void display_1()
       {display();
       cout<<"age: "<<age<<endl;        //�����������˽�г�Ա����ȷ��
       cout<<"address: "<<addr<<endl;}    //�����������˽�г�Ա����ȷ��
  private:
       int age;
       char addr[30];
 };
 
int main()
 {Student1 stud1;
  stud1.get_value_1();
  stud1.display_1();
  return 0;
} 
