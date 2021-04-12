#include <iostream>
#include <string>
using namespace std;
class Teacher                              //声明Teacher(教师)类
 {public:                                  //公用部分
   Teacher(string nam,int a,string t)      //构造函数
    {name=nam;
     age=a;
     title=t;}
   void display()                          //输出教师有关数据
     {cout<<"name:"<<name<<endl;
      cout<<"age"<<age<<endl;
      cout<<"title:"<<title<<endl;
     }
  protected:                               //保护部分
    string name;
    int age;
    string title;                          //职称
};

class Student                              //声明类Student(学生)
 {public:
   Student(string nam,char s,float sco)
     {name1=nam;
      sex=s;
      score=sco;}                         //构造函数
   void display1()                        //输出学生有关数据
    {cout<<"name:"<<name1<<endl;
     cout<<"sex:"<<sex<<endl;
     cout<<"score:"<<score<<endl;
    }
  protected:                               //保护部分
   string name1;
   char sex;
   float score;                            //成绩
 };

class Graduate:public Teacher,public Student   //声明多重继承的派生类Graduate
 {public:
   Graduate(string nam,int a,char s,string t,float sco,float w):
        Teacher(nam,a,t),Student(nam,s,sco),wage(w) {}
   void show( )                                 //输出人员的有关数据
    {cout<<"name:"<<name<<endl;
     cout<<"age:"<<age<<endl;
     cout<<"sex:"<<sex<<endl;
     cout<<"score:"<<score<<endl;
     cout<<"title:"<<title<<endl;
     cout<<"wages:"<<wage<<endl;
     }
  private:
    float wage;                     //工资
 };
 
int main( )
 {Graduate grad1("Wang-li",24,'f',"assistant",89.5,1234.5);
  grad1.show( );
  return 0;
}

