//��14.5�е�ͷ�ļ�1���ļ���Ϊheader11.h
using namespace std;
#include <string>
#include <cmath>
namespace Ns1
 {class Student
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
 }
