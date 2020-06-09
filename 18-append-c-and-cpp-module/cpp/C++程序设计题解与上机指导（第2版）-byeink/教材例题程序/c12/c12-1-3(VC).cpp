#include <iostream.h>
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

Point::Point(float a,float b)
{x=a;y=b;}
void Point::setPoint(float a,float b)
{x=a;y=b;}
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
 protected:
  float radius;
};

Circle::Circle(float a,float b,float r):Point(a,b),radius(r){}

void Circle::setRadius(float r)
{radius=r;}

float Circle::getRadius() const {return radius;}

float Circle::area() const
{return 3.14159*radius*radius;}

ostream &operator<<(ostream &output,const Circle &c)
{output<<"Center=["<<c.x<<","<<c.y<<"], r="<<c.radius<<", area="<<c.area()<<endl;
 return output;
}

class Cylinder:public Circle
{public:
  Cylinder (float x=0,float y=0,float r=0,float h=0);
  void setHeight(float);
  float getHeight() const;
  float area() const;
  float volume() const;
  friend ostream& operator<<(ostream&,const Cylinder&);
 protected:
  float height;
};

Cylinder::Cylinder(float a,float b,float r,float h)
    :Circle(a,b,r),height(h){}

void Cylinder::setHeight(float h){height=h;}

float Cylinder::getHeight() const {return height;}

float Cylinder::area() const
{ return 2*Circle::area()+2*3.14159*radius*height;}

float Cylinder::volume() const
{return Circle::area()*height;}

ostream &operator<<(ostream &output,const Cylinder& cy)
{output<<"Center=["<<cy.x<<","<<cy.y<<"], r="<<cy.radius<<", h="<<cy.height
       <<"\narea="<<cy.area()<<", volume="<<cy.volume()<<endl;
 return output;
}

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

