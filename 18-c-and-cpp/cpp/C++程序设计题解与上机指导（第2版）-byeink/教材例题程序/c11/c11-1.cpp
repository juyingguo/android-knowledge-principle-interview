#include <iostream>
#include <string>
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
   string name;
   char sex;
};   

class Student1: public Student
 {public:
   void get_value_1()
    {cin>>age>>addr;}
   void display_1()
    {  //cout<<"num: "<<num<<endl;        //企图引用基类的私有成员，错误
       //cout<<"name: "<<name<<endl;      //企图引用基类的私有成员，错误
       //cout<<"sex: "<<sex<<endl;        //企图引用基类的私有成员，错误
       cout<<"age: "<<age<<endl;          //引用派生类的私有成员，正确
       cout<<"address: "<<addr<<endl;}    //引用派生类的私有成员，正确
  private:
       int age;
       string addr;
 };
 
int main()
 {Student1 stud1;
  stud1.get_value();
  stud1.get_value_1();
  stud1.display();
  stud1.display_1();
  return 0;
} 
