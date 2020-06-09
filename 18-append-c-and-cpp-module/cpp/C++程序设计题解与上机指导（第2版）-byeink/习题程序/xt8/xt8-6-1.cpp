#include <iostream>
using namespace std;
class Box
{public:
  void get_value();
  float volume();
  void display();
 public:
  float lengh;
  float width;
  float height;
  };

void Box::get_value()
{ cout<<"please input lengh, width,height:";
  cin>>lengh;
  cin>>width;
  cin>>height;
}

float Box::volume()
{ return(lengh*width*height);}

void Box::display()
{ cout<<volume()<<endl;}

int main()
{Box box1,box2,box3;
 box1.get_value();
 cout<<"volmue of bax1 is ";
 box1.display();
 box2.get_value();
 cout<<"volmue of bax2 is ";
 box2.display();
 box3.get_value();
 cout<<"volmue of bax3 is ";
 box3.display();
 return 0;
}

