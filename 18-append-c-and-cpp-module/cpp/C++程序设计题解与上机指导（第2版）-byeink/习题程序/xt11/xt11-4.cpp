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
  cout<<"name: "<<name<<endl;
  cout<<"sex: "<<sex<<endl;
 }
   
class Student1: public Student              //声明一个公用派生类
{public:
   void get_value_1();
   void display1( );
 private:
   int age;                          
   char addr[30];
};

void Student1::get_value_1()
 {get_value();
  cin>>age>>addr;
 }
void Student1::display1( )
  {cout<<"num: "<<num<<endl;         //引用基类的保护成员，合法
   cout<<"name: "<<name<<endl;       //引用基类的保护成员，合法
   cout<<"sex: "<<sex<<endl;         //引用基类的保护成员，合法
   cout<<"age: "<<age<<endl;         //引用派生类的私有成员，合法
   cout<<"address: "<<addr<<endl;    //引用派生类的私有成员，合法
  }

int main( )
 {Student1 stud1;                      //stud1是派生类student1类的对象
  stud1.get_value_1();                 //调用派生类对象stud1的公用成员函数get_value_1
  stud1.display1( );                   //调用派生类对象stud1的公用成员函数display1
  return 0;
 }
