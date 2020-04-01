#include <iostream>
#include <string>
using namespace std;
class Student
 {public:
   Student(int n,string nam)
    {cout<<"construtot-"<<n<<endl;
     num=n;name=nam;}
   ~Student(){cout<<"destructor-"<<num<<endl;}
   void get_data();
  private:
   int num;
   string name;
 };
void Student::get_data()
 {if(num==0) throw num;
  else cout<<num<<" "<<name<<endl;
  cout<<"in get_data()"<<endl;
 }

void fun()
{Student stud1(1101,"tan");
 stud1.get_data();
 Student stud2(0,"Li");
 stud2.get_data();
}
int main()
{cout<<"main begin"<<endl;
 cout<<"call fun()"<<endl;
 try
  {fun();}
 catch(int n)
  {cout<<"num="<<n<<",error!"<<endl;}
 cout<<"main end"<<endl;
 return 0;
}
  
