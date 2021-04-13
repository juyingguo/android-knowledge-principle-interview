#include <iostream>
using namespace std;
class Student                        //声明基类
{public:                             //基类公用成员                
  void get_value();
  void display( );
 protected :                         //基类保护成员
    int num;
    char name[10];
    char sex;
};

void Student::get_value()
 {cin>>num>>name>>sex;}

void Student::display( )
 {cout<<"num: "<<num<<endl;
  cout<<"name:"<<name<<endl;
  cout<<"sex:"<<sex<<endl;
 }
 
class Student1: protected Student              //声明一个公用派生类
{public:
   void get_value_1();
   void display1( );
 private:
   int age;                          
   char addr[30];
};

void Student1::get_value_1()
 {cin>>age>>addr;}
 
void Student1::display1( )
  {cout<<"age:"<<age<<endl;
   cout<<"address:"<<addr<<endl;
  }

int main( )
 {Student1 stud1;                      //stud1是派生类student1类的对象
  stud1.get_value();
  stud1.get_value_1();
  stud1.display( );
  stud1.display1();                  //合法。display1是派生类中的公用成员函数
  return 0;
 }
