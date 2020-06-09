#include <iostream>
using namespace std;
class A
{public:
  void f1( );
 protected:
  void f2();
 private:
  int i;
};

class B: public A
{public:
  void f3( );
  int k;
 private:
  int m;
};

class C: protected B
{public:
  void f4();
 protected:
  int n;
 private:
  int p;
};

class D: private C
{public:
  void f5();
 protected:
  int q;
 private:
  int r;
};

int main()
{A a1;
 B b1;
 C c1;
 D d1;
 return 0;
}



