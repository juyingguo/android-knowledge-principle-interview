#include <iostream>
#include <string>
using namespace std;
class Student                              //声明基类
 {public:                                  //公用部分
   Student(int n,string nam)              //基类构造函数
    {num=n;
     name=nam;
    }
   void display()                           //输出基类数据成员
    {cout<<"num:"<<num<<endl<<"name:"<<name<<endl;}
  protected:                                //保护部分
    int num;
    string name;
};

class Student1: public Student              //用public继承方式声明派生类student
 {public:
   Student1(int n,string nam,int n1,string nam1,int a,string ad)
      :Student(n,nam),monitor(n1,nam1)               //派生类构造函数
    {age=a;                                 //在此处只对派生类新增的数据成员初始化
     addr=ad;
    }
   void show( )
    {cout<<"This student is:"<<endl;
     display();                               //输出num和name
     cout<<"age: "<<age<<endl;
     cout<<"address: "<<addr<<endl<<endl;
    }
    
   void show_monitor()                        //输出子对象的数据成员
    {cout<<endl<<"Class monitor is:"<<endl;
     monitor.display();                       //调用基类成员函数
    }
   private:                                //派生类的私有数据
    Student monitor;                       //定义子对象(班长)
    int age;
    string addr;                
  };
 
int main( )
 {Student1 stud1(10010,"Wang-li",10001,"Li-sun",19,"115 Beijing Road,Shanghai");
  stud1.show( );                             //输出第一个学生的数据
  stud1.show_monitor();                       //输出子对象的数据
  return 0;
 }






