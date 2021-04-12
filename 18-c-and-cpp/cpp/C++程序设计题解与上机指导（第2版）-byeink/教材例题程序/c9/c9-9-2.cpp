#include <iostream>
using namespace std;

class Box
 {public:
   Box(int=10,int=10,int=10);
   int volume();
  private:
   int height;
   int width;
   int length;
 };

Box::Box(int h,int w,int len)
 {height=h;
  width=w;
  length=len;
 }
int Box::volume()
 {return(height*width*length);
 }
 
    
int main()
 {Box box1(15,30,25);
  cout<<"The volume of box1 is "<<box1.volume()<<endl;
  Box box2=box1,box3=box2;
  cout<<"The volume of box2 is "<<box2.volume()<<endl;
  cout<<"The volume of box3 is "<<box3.volume()<<endl;
  return 0;
  
 }
 
 
