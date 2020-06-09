#include <iostream> 
using namespace std;
int main()
{int max_value(int array[][4]);
 int a[3][4]={{11,32,45,67},{22,44,66,88},{15,72,43,37}};
 cout<<"max value is "<<max_value(a)<<endl;
 return 0;
}
int max_value(int array[][4])
{int i,j,max;
 max=array[0][0];
 for( i=0;i<3;i++)
     for(j=0;j<4;j++)
       if(array[i][j]>max) max=array[i][j];
 return max;
}