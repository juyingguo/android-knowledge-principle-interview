#include <iostream>
using namespace std;
int main()
{void move(int *);
 int a[3][3],*p,i;
 cout<<"input matrix:"<<endl;
 for (i=0;i<3;i++)
   cin>>a[i][0]>>a[i][1]>>a[i][2];
 p=&a[0][0];
 move(p);
 cout<<"Now,matrix:"<<endl;
 for (i=0;i<3;i++)
   cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
 cout<<endl;
 return 0;
}

 void move(int *pointer)
  {int i,j,t;
   for (i=0;i<3;i++)
     for (j=i;j<3;j++)
       {t=*(pointer+3*i+j);
        *(pointer+3*i+j)=*(pointer+3*j+i);
        *(pointer+3*j+i)=t;
	 }
 }
  

	



	