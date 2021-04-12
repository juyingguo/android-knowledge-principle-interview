#include <iostream>
using namespace std;
class Student
 {public:
   Student(int n,float s):num(n),score(s){}
   void change(int n,float s) const  {num=n;score=s;}
   void display() const {cout<<num<<" "<<score<<endl;}
  private:
   mutable int num;
   mutable float score;
 };

int main()
{const Student stud(101,78.5);
 stud.display();
 stud.change(101,80.5);
 stud.display();
 return 0;
}
 


   
