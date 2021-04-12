#include <iostream>
#include<string>
using namespace std;
class Student                              //声明基类
 {public:                                  //公用部分
   Student(int n,string nam,char s )       //基类构造函数
    {num=n;
     name=nam;
     sex=s; }
   ~Student( ) { }
  protected:                               //保护部分
    int num;
    string name;
    char sex ;                            //基类析构函数
};

class Student1: public Student                   //声明公用派生类student
 {public:
   Student1(int n,string nam,char s,int a,char ad[]) : Student(n,nam,s),age(a)
                                             //派生类构造函数
    {age=a;                          //在函数体中只对派生类新增的数据成员初始化
     addr=ad;
    }
   void show( )
    {cout<<"num: "<<num<<endl;
     cout<<"name: "<<name<<endl;
     cout<<"sex: "<<sex<<endl;
     cout<<"age: "<<age<<endl;
     cout<<"address: "<<addr<<endl<<endl;
    }
   ~Student1( ) { }                      //派生类析构函数
  private:                               //派生类的私有部分
   int age;                          
   string addr;                
 };
 
int main( )
 {Student1 stud1(10010,"Wang-li",'f',19,"115 Beijing Road,Shanghai");
  Student1 stud2(10011,"Zhang-fun",'m',21,"213 Shanghai Road,Beijing");
  stud1.show( );            //输出第一个学生的数据
  stud2.show( );            //输出第二个学生的数据
  return 0;
}

