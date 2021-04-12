#include <iostream>
using namespace std;
int main()
{ const int n=4,m=5;        //假设数组为4行5列     
  int i,j,a[n][m],max,maxj;
  bool flag;
  for (i=0;i<n;i++)         //输入数组
     for (j=0;j<m;j++)
      cin>>a[i][j];
  for (i=0;i<n;i++)         
   {max=a[i][0]; maxj=0;    
    for (j=0;j<m;j++)      //找出第i行中的最大数
	  if (a[i][j]>max)
	    {max=a[i][j];      //将本行的最大数存放在max中
	     maxj=j;           //将最大数所在的列号存放在maxj中
	    }
    flag=true;            //先假设是鞍点，以flag为真代表
    for (int k=0;k<n;k++)
	  if (max>a[k][maxj])  //将最大数和其同列元素相比
	     {flag=false;     //如果max不是同列最小，表示不是鞍点令flag1为假
	      continue;}
    if(flag)             //如果flag1为真表示是鞍点
	{cout<<"a["<<i<<"]["<<"["<<maxj<<"]="<<max<<endl;
	                     //输出鞍点的值和所在行列号
	 break;
	}
  } 
  if(!flag)	            //如果flag为假表示鞍点不存在
    cout<<"It does not exist!"<<endl;
   return 0;
  } 


