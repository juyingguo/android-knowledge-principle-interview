#include <iostream>
#include <cstring>
using namespace std;
class Teacher                                //��ʦ��
 {public:
    Teacher(int,char [],char);               //�������캯��
    void display();                          //�����������
  private:
   int num;
   char name[20];
   char sex;
  };

Teacher::Teacher(int n,char nam[],char s)    //���幹�캯��
 {num=n;
  strcpy(name,nam);
  sex=s;
}

void Teacher::display()                      //�����������
 {cout<<"num:"<<num<<endl;
  cout<<"name:"<<name<<endl;
  cout<<"sex:"<<sex<<endl;
}

class BirthDate                               //������
 {public:
    BirthDate(int,int,int);                   //�������캯��
    void display();                           //�����������
    void change(int,int,int);                 //�����޸ĺ���
  private:
    int year;
    int month;
    int day;
};

BirthDate::BirthDate(int y,int m,int d)       //���幹�캯��
 {year=y;
  month=m;
  day=d;
 }
 
void BirthDate::display()                     //�����������
 {cout<<"birthday:"<<month<<"/"<<day<<"/"<<year<<endl;}

void BirthDate::change(int y,int m,int d)     //�����޸ĺ���
 {year=y;
  month=m;
  day=d;
 }
 
class Professor:public Teacher                         //������
 {public:
    Professor(int,char [],char,int,int,int,float);    //�������캯��
    void display();                                   //�����������
    void change(int,int,int);                         //�����޸ĺ���
   private:
    float area;
    BirthDate birthday;                               //����BirthDate��Ķ�����Ϊ���ݳ�Ա
 };

Professor::Professor(int n,char nam[20],char s,int y,int m,int d,float a):
 Teacher(n,nam,s),birthday(y,m,d),area(a){ }          //���幹�캯��

void Professor::display()                             //�����������
{Teacher::display();
 birthday.display();
 cout<<"area:"<<area<<endl;
}

void Professor::change(int y,int m,int d)             //�����޸ĺ���
 {birthday.change(y,m,d);
 }

int main()
{Professor prof1(3012,"Zhang",'f',1949,10,1,125.4);   //����Professor����prof1
 cout<<endl<<"original data:"<<endl;
 prof1.display();                                     //����prof1�����display����
 cout<<endl<<"new data:"<<endl;
 prof1.change(1950,6,1);                              //����prof1�����change����
 prof1.display();                                     //����prof1�����display����
 return 0;
}
