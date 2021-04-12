#include<string>
#include <iostream>
using namespace std;
class Teacher
 {public:
   Teacher(string nam,int a,char s,string tit,string ad,string t);
   void display();
  protected:
    string name;
    int age;
    char sex;
    string title;
    string addr;
    string tel;
};

Teacher::Teacher(string nam,int a,char s,string tit,string ad,string t):
     name(nam),age(a),sex(s),title(tit),addr(ad),tel(t){ }
void Teacher::display()
     {cout<<"name:"<<name<<endl;
      cout<<"age"<<age<<endl;
      cout<<"sex:"<<sex<<endl;
      cout<<"title:"<<title<<endl;
      cout<<"address:"<<addr<<endl;
      cout<<"tel:"<<tel<<endl;
      }

class Cadre
 {public:
   Cadre(string nam,int a,char s,string p,string ad,string t);
   void display();
  protected:
   string name;
   int age;
   char sex;
   string post;
   string addr;
   string tel;
 };
 
Cadre::Cadre(string nam,int a,char s,string p,string ad,string t):
     name(nam),age(a),sex(s),post(p),addr(ad),tel(t){}
     
void Cadre::display()
    {cout<<"name:"<<name<<endl;
     cout<<"age:"<<age<<endl;
     cout<<"sex:"<<sex<<endl;
     cout<<"post:"<<post<<endl;
     cout<<"address:"<<addr<<endl;
     cout<<"tel:"<<tel<<endl;
    }

class Teacher_Cadre:public Teacher,public Cadre
 {public:
   Teacher_Cadre(string nam,int a,char s,string tit,string p,string ad,string t,float w);
   void show( );
  private:
    float wage;
 };
 
Teacher_Cadre::Teacher_Cadre(string nam,int a,char s,string t,string p,string ad,string tel,float w):
  Teacher(nam,a,s,t,ad,tel),Cadre(nam,a,s,p,ad,tel),wage(w) {}
void Teacher_Cadre::show( )
    {Teacher::display();
     cout<<"post:"<<Cadre::post<<endl;
     cout<<"wages:"<<wage<<endl;
     }

int main( )
 {Teacher_Cadre te_ca("Wang-li",50,'f',"prof.","president","135 Beijing Road,Shanghai","(021)61234567",1534.5);
  te_ca.show( );
  return 0;
}

