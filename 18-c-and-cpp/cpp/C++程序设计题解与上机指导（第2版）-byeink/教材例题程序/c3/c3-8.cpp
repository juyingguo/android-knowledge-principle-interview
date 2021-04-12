#include <iostream>
using namespace std;
int main()
{
  int year;
  bool leap;
  cout<<"please enter year:";
  cin>>year;
  if (year%4==0)
    {if(year%100==0)
      {if (year%400==0)
          leap=true;
       else leap=false;}
     else
		 leap=true;}
  else
      leap=false;
  if (leap)
     cout<<year<<" is ";
  else
     cout<<year<<" is not ";
     cout<<" a leap year."<<endl;
  return 0;
}