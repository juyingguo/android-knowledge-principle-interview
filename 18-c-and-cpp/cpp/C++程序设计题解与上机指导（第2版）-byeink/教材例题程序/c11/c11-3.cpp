#include <iostream>
#include <string>
using namespace std;
class Student                        //声明基类
{public:                             //基类公用成员                
  void display( );
 protected :                         //基类保护成员
    int num;
    string name;
    char sex;
};

void Student::display( )
   {cout<<"num: "<<num<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"sex: "<<sex<<endl;
   }
   
class Student1: protected Student     //用protected继承方式声明一个派生类
{public:
   void display1( );
 private:
   int age;                          
   string addr;
};

void Student1::display1( )
    {cout<<"num: "<<num<<endl;         //引用基类的保护成员，合法
     cout<<"name: "<<name<<endl;       //引用基类的保护成员，合法
     cout<<"sex: "<<sex<<endl;         //引用基类的保护成员，合法
     cout<<"age: "<<age<<endl;         //引用派生类的私有成员，合法
     cout<<"address: "<<addr<<endl;    //引用派生类的私有成员，合法
   

int main( )
 {Student1 stud1;                      //stud2是派生类student2的对象
  stud1.display1( );                  //display是派生类中的公用成员函数
  return 0;
 }
