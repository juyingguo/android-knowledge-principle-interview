#include <iostream>
#include <string>
using namespace std;
class Student                              //��������
 {public:                                  //���ò���
   Student(int n,string nam)              //���๹�캯��
    {num=n;
     name=nam;
    }
   void display()                           //����������ݳ�Ա
    {cout<<"num:"<<num<<endl<<"name:"<<name<<endl;}
  protected:                                //��������
    int num;
    string name;
};

class Student1: public Student              //��public�̳з�ʽ����������student
 {public:
   Student1(int n,string nam,int n1,string nam1,int a,string ad)
      :Student(n,nam),monitor(n1,nam1)               //�����๹�캯��
    {age=a;                                 //�ڴ˴�ֻ�����������������ݳ�Ա��ʼ��
     addr=ad;
    }
   void show( )
    {cout<<"This student is:"<<endl;
     display();                               //���num��name
     cout<<"age: "<<age<<endl;
     cout<<"address: "<<addr<<endl<<endl;
    }
    
   void show_monitor()                        //����Ӷ�������ݳ�Ա
    {cout<<endl<<"Class monitor is:"<<endl;
     monitor.display();                       //���û����Ա����
    }
   private:                                //�������˽������
    Student monitor;                       //�����Ӷ���(�೤)
    int age;
    string addr;                
  };
 
int main( )
 {Student1 stud1(10010,"Wang-li",10001,"Li-sun",19,"115 Beijing Road,Shanghai");
  stud1.show( );                             //�����һ��ѧ��������
  stud1.show_monitor();                       //����Ӷ��������
  return 0;
 }






