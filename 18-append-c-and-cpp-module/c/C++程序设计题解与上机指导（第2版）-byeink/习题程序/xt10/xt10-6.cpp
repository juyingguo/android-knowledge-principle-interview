#include <iostream>
using namespace std;
class Complex
 {public:
   Complex(){real=0;imag=0;}
   Complex(double r){real=r;imag=0;}
   Complex(double r,double i){real=r;imag=i;}
   operator double(){return real;}
   void display();
  private:
   double real;
   double imag;
 };
   
void Complex::display()
{cout<<"("<<real<<", "<<imag<<")"<<endl;}

int main()
{Complex c1(3,4),c2;
 double d1;
 d1=2.5+c1;
 cout<<"d1="<<d1<<endl;
 c2=Complex(d1);
 cout<<"c2=";
 c2.display();
 return 0;
}

