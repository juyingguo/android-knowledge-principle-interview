#include <iostream>
#include <string>
using namespace std;
//定义公共基类Person
class Person                              
{public:
  Person(char *nam,char s,int a)            //构造函数     
   {strcpy(name,nam);sex=s;age=a;}
 protected:                                 //保护成员
   char name[20];
   char sex;
   int age;
};
//定义类Teacher
class Teacher:virtual public Person                //声明Person为公用继承的虚基类
 {public:                                 
   Teacher(char *nam,char s,int a,char *t):Person(nam,s,a)       //构造函数
    {strcpy(title,t); 
    }
  protected:                                       //保护成员
    char title[10];                                //职称
};
//定义类Student
class Student:virtual public Person               //声明Person为公用继承的虚基类
 {public:
   Student(char *nam,char s,int a,float sco):    //构造函数
      Person(nam,s,a),score(sco){}               //初始化表
  protected:                                     //保护成员
    float score;                                 //成绩
 };
//定义多重继承的派生类Graduate
class Graduate:public Teacher,public Student     //声明Teacher和Student类为公用继承的直接基类
 {public:
   Graduate(char *nam,char s,int a,char *t,float sco,float w):                  //构造函数
       Person(nam,s,a),Teacher(nam,s,a,t),Student(nam,s,a,sco),wage(w){}       //初始化表
    void show( )                                 //输出研究生的有关数据
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
 {Graduate grad1("Wang-li",'f',24,"assistant",89.5,1234.5);
  grad1.show( );
  return 0;
}

