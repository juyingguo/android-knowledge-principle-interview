#include <iostream>
#include <cstring>
using namespace std;
class Teacher                                //教师类
 {public:
    Teacher(int,char [],char);               //声明构造函数
    void display();                          //声明输出函数
  private:
   int num;
   char name[20];
   char sex;
  };

Teacher::Teacher(int n,char nam[],char s)    //定义构造函数
 {num=n;
  strcpy(name,nam);
  sex=s;
}

void Teacher::display()                      //定义输出函数
 {cout<<"num:"<<num<<endl;
  cout<<"name:"<<name<<endl;
  cout<<"sex:"<<sex<<endl;
}

class BirthDate                               //生日类
 {public:
    BirthDate(int,int,int);                   //声明构造函数
    void display();                           //声明输出函数
    void change(int,int,int);                 //声明修改函数
  private:
    int year;
    int month;
    int day;
};

BirthDate::BirthDate(int y,int m,int d)       //定义构造函数
 {year=y;
  month=m;
  day=d;
 }
 
void BirthDate::display()                     //定义输出函数
 {cout<<"birthday:"<<month<<"/"<<day<<"/"<<year<<endl;}

void BirthDate::change(int y,int m,int d)     //定义修改函数
 {year=y;
  month=m;
  day=d;
 }
 
class Professor:public Teacher                         //教授类
 {public:
    Professor(int,char [],char,int,int,int,float);    //声明构造函数
    void display();                                   //声明输出函数
    void change(int,int,int);                         //声明修改函数
   private:
    float area;
    BirthDate birthday;                               //定义BirthDate类的对象作为数据成员
 };

Professor::Professor(int n,char nam[20],char s,int y,int m,int d,float a):
 Teacher(n,nam,s),birthday(y,m,d),area(a){ }          //定义构造函数

void Professor::display()                             //定义输出函数
{Teacher::display();
 birthday.display();
 cout<<"area:"<<area<<endl;
}

void Professor::change(int y,int m,int d)             //定义修改函数
 {birthday.change(y,m,d);
 }

int main()
{Professor prof1(3012,"Zhang",'f',1949,10,1,125.4);   //定义Professor对象prof1
 cout<<endl<<"original data:"<<endl;
 prof1.display();                                     //调用prof1对象的display函数
 cout<<endl<<"new data:"<<endl;
 prof1.change(1950,6,1);                              //调用prof1对象的change函数
 prof1.display();                                     //调用prof1对象的display函数
 return 0;
}
