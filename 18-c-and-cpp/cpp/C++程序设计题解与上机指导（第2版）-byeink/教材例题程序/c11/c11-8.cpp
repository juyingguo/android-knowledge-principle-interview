#include <iostream>
#include <string>
using namespace std;
class Teacher                              //����Teacher(��ʦ)��
 {public:                                  //���ò���
   Teacher(string nam,int a,string t)      //���캯��
    {name=nam;
     age=a;
     title=t;}
   void display()                          //�����ʦ�й�����
     {cout<<"name:"<<name<<endl;
      cout<<"age"<<age<<endl;
      cout<<"title:"<<title<<endl;
     }
  protected:                               //��������
    string name;
    int age;
    string title;                          //ְ��
};

class Student                              //������Student(ѧ��)
 {public:
   Student(string nam,char s,float sco)
     {name1=nam;
      sex=s;
      score=sco;}                         //���캯��
   void display1()                        //���ѧ���й�����
    {cout<<"name:"<<name1<<endl;
     cout<<"sex:"<<sex<<endl;
     cout<<"score:"<<score<<endl;
    }
  protected:                               //��������
   string name1;
   char sex;
   float score;                            //�ɼ�
 };

class Graduate:public Teacher,public Student   //�������ؼ̳е�������Graduate
 {public:
   Graduate(string nam,int a,char s,string t,float sco,float w):
        Teacher(nam,a,t),Student(nam,s,sco),wage(w) {}
   void show( )                                 //�����Ա���й�����
    {cout<<"name:"<<name<<endl;
     cout<<"age:"<<age<<endl;
     cout<<"sex:"<<sex<<endl;
     cout<<"score:"<<score<<endl;
     cout<<"title:"<<title<<endl;
     cout<<"wages:"<<wage<<endl;
     }
  private:
    float wage;                     //����
 };
 
int main( )
 {Graduate grad1("Wang-li",24,'f',"assistant",89.5,1234.5);
  grad1.show( );
  return 0;
}

