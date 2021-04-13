#include <iostream>
using namespace std;
class Student
{public:
  Student(int,char[],char,float);
  int get_num(){return num;}
  char * get_name(){return name;}
  char get_sex(){return sex;}
  void display()
   {cout<<"num:"<<num<<"\nname:"<<name<<"\nsex:"<<sex<<"\nscore:"<<score<<"\n\n";}
 private:
  int num;
  char name[20];
  char sex;
  float score;
};

Student::Student(int n,char nam[],char s,float so)
 {num=n;
  strcpy(name,nam);
  sex=s;
  score=so;
}

class Teacher
 {public:
  Teacher(){}
  Teacher(Student&);
   Teacher(int n,char nam[],char sex,float pay);
   void display();
  private:
   int num;
   char name[20];
   char sex;
   float pay;
 };
 
Teacher::Teacher(int n,char nam[],char s,float p)
{num=n;
 strcpy(name,nam);
 sex=s;
 pay=p;
}

Teacher::Teacher(Student& stud)
 {num=stud.get_num();
  strcpy(name,stud.get_name());
  sex=stud.get_sex();
  pay=1500;}

void Teacher::display()
{cout<<"num:"<<num<<"\nname:"<<name<<"\nsex:"<<sex<<"\npay:"<<pay<<"\n\n";}

  
int main()
{Teacher teacher1(10001,"Li",'f',1234.5),teacher2;
 Student student1(20010,"Wang",'m',89.5);
 cout<<"student1:"<<endl;
 student1.display();
 teacher2=Teacher(student1);
 cout<<"teacher2:"<<endl;
 teacher2.display();
 return 0;
}

