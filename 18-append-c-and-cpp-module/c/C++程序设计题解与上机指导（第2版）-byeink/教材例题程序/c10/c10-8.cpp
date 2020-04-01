#include <iostream>
using namespace std;
class Complex
 {public:
   friend ostream& operator << (ostream&,Complex&);
   friend istream& operator >> (istream&,Complex&);
  private:
   double real;
   double imag;
 };
   
ostream& operator << (ostream& output,Complex& c)
{output<<"("<<c.real<<"+"<<c.imag<<"i)";
 return output;
}

istream& operator >> (istream& input,Complex& c)
{cout<<"input real part and imaginary part of complex number:";
 input>>c.real>>c.imag;
 return input;
}


int main()
{Complex c1,c2;
 cin>>c1>>c2;
 cout<<"c1="<<c1<<endl;
 cout<<"c2="<<c2<<endl;
 return 0;
}

