#include <iostream>
#include <string>
using namespace std;
class Student
{public:
  void get_value()
   {cin>>num>>name>>sex;}
  void display( )
    {cout<<"num: "<<num<<endl;
     cout<<"name: "<<name<<endl;
     cout<<"sex: "<<sex<<endl;}
 private :
   int num;
   string name;
   char sex;
};   

class Student1: public Student
 {public:
   void get_value_1()
    {cin>>age>>addr;}
   void display_1()
    {  //cout<<"num: "<<num<<endl;        //��ͼ���û����˽�г�Ա������
       //cout<<"name: "<<name<<endl;      //��ͼ���û����˽�г�Ա������
       //cout<<"sex: "<<sex<<endl;        //��ͼ���û����˽�г�Ա������
       cout<<"age: "<<age<<endl;          //�����������˽�г�Ա����ȷ
       cout<<"address: "<<addr<<endl;}    //�����������˽�г�Ա����ȷ
  private:
       int age;
       string addr;
 };
 
int main()
 {Student1 stud1;
  stud1.get_value();
  stud1.get_value_1();
  stud1.display();
  stud1.display_1();
  return 0;
} 
