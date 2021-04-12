#include <iostream>
using namespace std;
//������Point
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
//����Point��ĳ�Ա����
//Point�Ĺ��캯��
Point::Point(float a,float b)
{x=a;y=b;}
//����x��y������ֵ
void Point::setPoint(float a,float b)
{x=a;y=b;}
//����������
ostream & operator<<(ostream &output,const Point &p)
{output<<"["<<p.x<<","<<p.y<<"]"<<endl;
 return output;
}

class Circle:public Point
{public:
  Circle(float x=0,float y=0,float r=0);
  void setRadius(float);
  float getRadius() const;
  float area () const;
  friend ostream &operator<<(ostream &,const Circle &);
 private:
  float radius;
};

Circle::Circle(float a,float b,float r):Point(a,b),radius(r){}

void Circle::setRadius(float r)
{radius=r;}

float Circle::getRadius() const {return radius;}

float Circle::area() const
{return 3.14159*radius*radius;}

ostream &operator<<(ostream &output,const Circle &c)
{output<<"Center=["<<c.x<<","<<c.y<<"], Radius="<<c.radius<<", area="<<c.area()<<endl;
 return output;
}

int main()
{Circle c(3.5,6.4,5.2);
 cout<<"original circle:\nx="<<c.getX()<<", y="<<c.getY()<<", r="<<c.getRadius()
     <<", area="<<c.area()<<endl;
 c.setRadius(7.5);
 c.setPoint(5,5);
 cout<<"new circle:\n"<<c;
 Point &pRef=c;
 cout<<"pRef:"<<pRef;
 return 0;
}
