#include <iostream>
#include <string>
using namespace std;
//���幫������Person
class Person                              
{public:
  Person(char *nam,char s,int a)            //���캯��     
   {strcpy(name,nam);sex=s;age=a;}
 protected:                                 //������Ա
   char name[20];
   char sex;
   int age;
};
//������Teacher
class Teacher:virtual public Person                //����PersonΪ���ü̳е������
 {public:                                 
   Teacher(char *nam,char s,int a,char *t):Person(nam,s,a)       //���캯��
    {strcpy(title,t); 
    }
  protected:                                       //������Ա
    char title[10];                                //ְ��
};
//������Student
class Student:virtual public Person               //����PersonΪ���ü̳е������
 {public:
   Student(char *nam,char s,int a,float sco):    //���캯��
      Person(nam,s,a),score(sco){}               //��ʼ����
  protected:                                     //������Ա
    float score;                                 //�ɼ�
 };
//������ؼ̳е�������Graduate
class Graduate:public Teacher,public Student     //����Teacher��Student��Ϊ���ü̳е�ֱ�ӻ���
 {public:
   Graduate(char *nam,char s,int a,char *t,float sco,float w):                  //���캯��
       Person(nam,s,a),Teacher(nam,s,a,t),Student(nam,s,a,sco),wage(w){}       //��ʼ����
    void show( )                                 //����о������й�����
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
 {Graduate grad1("Wang-li",'f',24,"assistant",89.5,1234.5);
  grad1.show( );
  return 0;
}

