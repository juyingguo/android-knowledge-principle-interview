#include <iostream>
using namespace std;
int main()
  {char i,j,k;                /* i是a的对手;j是b的对手;k是c的对手*/
   for (i='X';i<='Z';i++)
     for (j='X';j<='Z';j++)
        if (i!=j)
          for (k='X';k<='Z';k++)
	        if (i!=k && j!=k)
	          if (i!='X' && k!='X' && k!='Z')
	            cout<<"A--"<<i<<"  B--"<<j<<"  C--"<<k<<endl;
    return 0;
   } 
  