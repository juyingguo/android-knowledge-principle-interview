//header2.h
#include <string>
namespace student2
 {class Student
   {public:
     Student(int n,string nam,char s,float sco)
       {num=n;name=nam;sex=s;score=sco;}
     void show_data();
    private:
     int num;
     string name;
     char sex;
     float score;
   };
   
  void Student::show_data()
   {cout<<"num:"<<num<<"  name:"<<name<<" sex:"<<sex
        <<"   score:"<<score<<endl; }
 }
