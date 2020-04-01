#include <iostream>
using namespace std;
class Student
 {public:
   Student(int n,float s):num(n),score(s){}
   void change(int n,float s) {num=n;score=s;}
   void display() {cout<<num<<" "<<score<<endl;}
  private:
   int num;
   float score;
 };

int main()
{Student stud(101,78.5);
 Student *p=&stud;
 p->display();
 p->change(101,80.5);
 p->display();
 return 0;
}
 


   
