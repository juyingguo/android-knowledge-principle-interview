#include <iostream>
using namespace std;
class Student                        //��������
{public:                             //���๫�ó�Ա                
  void get_value();
  void display( );
 protected :                         //���ౣ����Ա
    int num;
    char name[10];
    char sex;
};

void Student::get_value()
 {cin>>num>>name>>sex;}

void Student::display( )
 {cout<<"num: "<<num<<endl;
  cout<<"name: "<<name<<endl;
  cout<<"sex: "<<sex<<endl;
 }
   
class Student1: public Student              //����һ������������
{public:
   void get_value_1();
   void display1( );
 private:
   int age;                          
   char addr[30];
};

void Student1::get_value_1()
 {get_value();
  cin>>age>>addr;
 }
void Student1::display1( )
  {cout<<"num: "<<num<<endl;         //���û���ı�����Ա���Ϸ�
   cout<<"name: "<<name<<endl;       //���û���ı�����Ա���Ϸ�
   cout<<"sex: "<<sex<<endl;         //���û���ı�����Ա���Ϸ�
   cout<<"age: "<<age<<endl;         //�����������˽�г�Ա���Ϸ�
   cout<<"address: "<<addr<<endl;    //�����������˽�г�Ա���Ϸ�
  }

int main( )
 {Student1 stud1;                      //stud1��������student1��Ķ���
  stud1.get_value_1();                 //�������������stud1�Ĺ��ó�Ա����get_value_1
  stud1.display1( );                   //�������������stud1�Ĺ��ó�Ա����display1
  return 0;
 }
