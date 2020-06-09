#include <iostream>
using namespace std;
int main()
  {int hcf(int,int);
   int lcd(int,int,int);
   int u,v,h,l;
   cin>>u>>v;
   h=hcf(u,v);
   cout<<"H.C.F="<<h<<endl;
   l=lcd(u,v,h);
   cout<<"L.C.D="<<l<<endl;
   return 0;
  }

int hcf(int u,int v)
 {int t,r;
  if (v>u)
    {t=u;u=v;v=t;}
     while ((r=u%v)!=0)
        {u=v;
         v=r;}
         return(v);
     }

int lcd(int u,int v,int h)
 {return(u*v/h);
                    }


