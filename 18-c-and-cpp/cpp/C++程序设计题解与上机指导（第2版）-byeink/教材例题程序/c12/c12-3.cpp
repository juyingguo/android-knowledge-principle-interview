#include <iostream>
using namespace std;
class Point
{public:
  Point(){}
  ~Point(){cout<<"executing Point destructor"<<endl;}
};

class Circle:public Point
{public:
  Circle(){}
  ~Circle(){cout<<"executing Circle destructor"<<endl;}
 private:
  int radus;
};

int main()
{Point *p=new Circle;
 delete p;
 return 0;
}

