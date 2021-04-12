#include <iostream>
using namespace std;
int main()
{float grade;
 cout<<"enter grade:";
 while(cin>>grade)
  {if(grade>=85) cout<<grade<<" GOOD!"<<endl;
   if(grade<60) cout<<grade<<" fail!"<<endl;
   cout<<"enter grade:";
  }
 cout<<"The end."<<endl;
 return 0;
}

