#include <iostream.h>
//声明抽象基类Shape
class Shape
{public:
 virtual float area() const {return 0.0;}        //虚函数
 virtual float volume() const {return 0.0;}      //虚函数
 virtual void shapeName() const =0;              //纯虚函数
};

//声明Point类
class Point:public Shape                         //Point是Shape的公用派生类
{public:
  Point(float=0,float=0);
  void setPoint(float,float);
  float getX() const {return x;}
  float getY() const {return y;}
  virtual void shapeName() const {cout<<"Point:";}  //对纯虚函数进行定义
  friend ostream & operator<<(ostream &,const Point &);
protected:
  float x,y;
};

Point::Point(float a,float b)
{x=a;y=b;}

void Point::setPoint(float a,float b)
{x=a;y=b;}

ostream & operator<<(ostream &output,const Point &p)
{output<<"["<<p.x<<","<<p.y<<"]";
 return output;
}

//声明Circle类
class Circle:public Point
{public:
  Circle(float x=0,float y=0,float r=0);
  void setRadius(float);
  float getRadius() const;
  virtual float area() const;
  virtual void shapeName() const {cout<<"Circle:";}         //对纯虚函数进行再定义
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
{output<<"["<<c.x<<","<<c.y<<"], r="<<c.radius;
 return output;
}

//声明Cylinder类
class Cylinder:public Circle
{public:
  Cylinder (float x=0,float y=0,float r=0,float h=0);
  void setHeight(float);
  float getHeight() const;
  virtual float area() const;
  virtual float volume() const;
  virtual void shapeName() const {cout<<"Cylinder:";}         //对纯虚函数进行再定义
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
{output<<"["<<cy.x<<","<<cy.y<<"], r="<<cy.radius<<", h="<<cy.height;
 return output;
}

int main()
{Point point(3.2,4.5);                           //建立Point类对象point
 Circle circle(2.4,12,5.6);                      //建立Circle类对象circle
 Cylinder cylinder(3.5,6.4,5.2,10.5);            //建立Cylinder类对象cylinder

 point.shapeName();                              //静态关联
 cout<<point<<endl;
 
 circle.shapeName();                             //静态关联
 cout<<circle<<endl;

 cylinder.shapeName();                           //静态关联
 cout<<cylinder<<endl<<endl;

 Shape *pt;                                      //定义基类指针

 pt=&point;                                      //指针指向Point类对象
 pt->shapeName();                                //动态关联
 cout<<"x="<<point.getX()<<",y="<<point.getY()<<"\narea="<<pt->area()
     <<"\nvolume="<<pt->volume()<<"\n\n";

 pt=&circle;                                     //指针指向Circle类对象
 pt->shapeName();                                //动态关联
 cout<<"x="<<circle.getX()<<",y="<<circle.getY()<<"\narea="<<pt->area()
     <<"\nvolume="<<pt->volume()<<"\n\n";

 pt=&cylinder;                                   //指针指向Cylinder类对象
 pt->shapeName();                                //动态关联
 cout<<"x="<<cylinder.getX()<<",y="<<cylinder.getY()<<"\narea="<<pt->area()
     <<"\nvolume="<<pt->volume()<<"\n\n";
 return 0;
}

