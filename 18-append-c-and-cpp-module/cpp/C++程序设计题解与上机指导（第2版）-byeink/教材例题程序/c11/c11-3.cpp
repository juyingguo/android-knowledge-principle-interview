#include <iostream>
#include <string>
using namespace std;
class Student                        //��������
{public:                             //���๫�ó�Ա                
  void display( );
 protected :                         //���ౣ����Ա
    int num;
    string name;
    char sex;
};

void Student::display( )
   {cout<<"num: "<<num<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"sex: "<<sex<<endl;
   }
   
class Student1: protected Student     //��protected�̳з�ʽ����һ��������
{public:
   void display1( );
 private:
   int age;                          
   string addr;
};

void Student1::display1( )
    {cout<<"num: "<<num<<endl;         //���û���ı�����Ա���Ϸ�
     cout<<"name: "<<name<<endl;       //���û���ı�����Ա���Ϸ�
     cout<<"sex: "<<sex<<endl;         //���û���ı�����Ա���Ϸ�
     cout<<"age: "<<age<<endl;         //�����������˽�г�Ա���Ϸ�
     cout<<"address: "<<addr<<endl;    //�����������˽�г�Ա���Ϸ�
   

int main( )
 {Student1 stud1;                      //stud2��������student2�Ķ���
  stud1.display1( );                  //display���������еĹ��ó�Ա����
  return 0;
 }
