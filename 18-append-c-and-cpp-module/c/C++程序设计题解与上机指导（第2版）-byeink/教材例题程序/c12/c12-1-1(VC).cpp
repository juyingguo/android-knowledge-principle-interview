#include <iostream.h>
//using namespace std;
//声明类Point
class Point
{public:
  Point(float=0,float=0);
  void setPoint(float,float);
  float getX() const {return x;}
  float getY() const {return y;}
  friend ostream & operator<<(ostream &,const Point &);
protected:
  float x,y;
};
//定义Point类的成员函数
//Point的构造函数
Point::Point(float a,float b)
{x=a;y=b;}
//设置x和y的坐标值
void Point::setPoint(float a,float b)
{x=a;y=b;}
//输出点的坐标
ostream & operator<<(ostream &output,const Point &p)
{output<<"["<<p.x<<","<<p.y<<"]"<<endl;
 return output;
}
int main()
{Point p(3.5,6.4);
 cout<<"x="<<p.getX()<<",y="<<p.getY()<<endl;
 p.setPoint(8.5,6.8);
 cout<<"p(new):"<<p<<endl;
 return 0;
}
