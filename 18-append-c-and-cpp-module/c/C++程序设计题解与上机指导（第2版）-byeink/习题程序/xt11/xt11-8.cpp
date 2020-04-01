#include <iostream>
using namespace std;
class A
 {
  public:
   A(){cout<<"constructing A "<<endl;}
   ~A(){cout<<"destructing A "<<endl;}
 };

class B  : public A
 {
  public:
   B(){cout<<"constructing B "<<endl;}
   ~B(){cout<<"destructing B "<<endl;}
};

class C  : public B
 {
  public:
   C(){cout<<"constructing C "<<endl;}
   ~C(){cout<<"destructing C "<<endl;}
};
int main()
{ C c1;
  return 0;
}

