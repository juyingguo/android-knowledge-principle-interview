#include <iostream>
using namespace std;
class Point
{public:
  Point(){}
  virtual ~Point(){cout<<"executing Point destructor"<<endl;}
};

class Circle:public Point
{public:
  Circle(){}
  ~Circle(){cout<<"executing Circle destructor"<<endl;}
 private:
  int radus;
};

void main()
{Point *p=new Circle;
 delete p;
}

