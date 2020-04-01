#include <iostream>     //如用VC++应改为∶#include  <iosttram.h>
using namespace std;    //如用VC++应取消此行
#include "cylinder.h"
#include "point.cpp"
#include "circle.cpp"
#include "cylinder.cpp"
int main()
{Cylinder cy1(3.5,6.4,5.2,10);
 cout<<"\noriginal cylinder:\nx="<<cy1.getX()<<", y="<<cy1.getY()<<", r="
     <<cy1.getRadius()<<", h="<<cy1.getHeight()<<"\narea="<<cy1.area()
     <<", volume="<<cy1.volume()<<endl;
 cy1.setHeight(15);
 cy1.setRadius(7.5);
 cy1.setPoint(5,5);
 cout<<"\nnew cylinder:\n"<<cy1;
 Point &pRef=cy1;
 cout<<"\npRef as a point:"<<pRef;
 Circle &cRef=cy1;
 cout<<"\ncRef as a Circle:"<<cRef;
 return 0;
}
