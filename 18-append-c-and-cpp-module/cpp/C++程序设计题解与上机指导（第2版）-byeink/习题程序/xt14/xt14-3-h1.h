//header1.h
#include <string>
namespace student1
 {class Student
    {public:
      Student(int n,string nam,int a,string addr)
       {num=n;name=nam;age=a;address=addr;}
      void show_data();
     private:
      int num;
      string name;
      int age;
      string address;
    };
  void Student::show_data()
    {cout<<"num:"<<num<<"  name:"<<name<<"  age:"<<age
         <<"  address:"<<address<<endl;
    }
 }
    

