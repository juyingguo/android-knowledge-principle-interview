//例14.4中的头文件header1
#include <string>
#include <cmath>
using namespace std;
class Student
 {public:
   Student(int n,string nam,int a)
     {num=n;name=nam;age=a;}
   void get_data();
  private:
   int num;
   string name;
   int age;
 };
void Student::get_data()
 {cout<<num<<" "<<name<<" "<<age<<endl;
 }
double fun(double a,double b)
 {return sqrt(a+b);}
