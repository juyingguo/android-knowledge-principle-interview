#include <iostream>
using namespace std;
class Product
 {public:
   Product(int n,int q,float p):num(n),quantity(q),price(p){};
   void total();
   static float average();
   static void display();

  private:
   int num;
   int quantity;
   float price;
   static float discount;
   static float sum;
   static int n;
 };

void Product::total()
 {float rate=1.0;
  if(quantity>10) rate=0.98*rate;
  sum=sum+quantity*price*rate*(1-discount);
  n=n+quantity;
 }

void Product::display()
 {cout<<sum<<endl;
  cout<<average()<<endl;
 }

float Product::average()
 {return(sum/n);}
 
 
float Product::discount=0.05;
float Product::sum=0;
int Product::n=0;

int main()
 {
   Product Prod[3]={
     Product(101,5,23.5),Product(102,12,24.56),Product(103,100,21.5)
    };
   for(int i=0;i<3;i++)
     Prod[i].total();
   Product::display();
   return 0;
 }
 
 
