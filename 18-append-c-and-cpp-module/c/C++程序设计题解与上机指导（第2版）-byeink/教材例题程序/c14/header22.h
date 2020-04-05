//例14.5中的头文件2，文件名为header12.h
#include <string>
#include <cmath>
namespace Ns2
 {class Student
   {public:
     Student(int n,string nam,char s)
       {num=n;name=nam;sex=s;}
     void get_data();
    private:
     int num;
     string name;
     char sex;
   };
   
  void Student::get_data()
   {cout<<num<<" "<<name<<" "<<sex<<endl;
   }
  double fun(double a,double b)
   {return sqrt(a-b);}
 }
