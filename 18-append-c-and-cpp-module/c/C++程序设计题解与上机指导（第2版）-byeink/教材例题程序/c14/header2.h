//例14.4中的头文件header2
#include <string>
#include <cmath>
using namespace std;
class Student
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
