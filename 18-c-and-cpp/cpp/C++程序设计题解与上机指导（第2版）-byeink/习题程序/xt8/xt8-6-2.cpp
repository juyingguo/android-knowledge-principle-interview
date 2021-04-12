#include <iostream>
using namespace std;
class Box
{public:
  void get_value();
  void volume();
  void display();
 public:
  float lengh;
  float width;
  float height;
  float vol;
  };

void Box::get_value()
{ cout<<"please input lengh, width,height:";
  cin>>lengh;
  cin>>width;
  cin>>height;
}

void Box::volume()
{ vol=lengh*width*height;}

void Box::display()
{ cout<<vol<<endl;}

int main()
{Box box1,box2,box3;
 box1.get_value();
 box1.volume();
 cout<<"volmue of bax1 is ";
 box1.display();
 box2.get_value();
 box2.volume();
 cout<<"volmue of bax2 is ";
 box2.display();
 box3.get_value();
 box3.volume();
 cout<<"volmue of bax3 is ";
 box3.display();
 return 0;
}

