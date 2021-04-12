#include <iostream>
using namespace std;
int main ()
{long int num;
  int indiv,ten,hundred,thousand,ten_thousand,place; 
                                   /*分别代表个位,十位,百位,千位,万位和位数*/
  cout<<"enter an integer(0~99999):";
  cin>>num;
  if (num>9999)
       place=5;
  else  if (num>999)
       place=4;
  else  if (num>99)
       place=3;
  else  if (num>9)
       place=2;
  else place=1;
  cout<<"place="<<place<<endl;
  //计算各位数字
  ten_thousand=num/10000;
  thousand=(int)(num-ten_thousand*10000)/1000;
  hundred=(int)(num-ten_thousand*10000-thousand*1000)/100;
  ten=(int)(num-ten_thousand*10000-thousand*1000-hundred*100)/10;
  indiv=(int)(num-ten_thousand*10000-thousand*1000-hundred*100-ten*10);
  cout<<"original order:";
  switch(place)
    {case 5:cout<<ten_thousand<<","<<thousand<<","<<hundred<<","<<ten<<","<<indiv<<endl;
	    cout<<"reverse order:";
	    cout<<indiv<<ten<<hundred<<thousand<<ten_thousand<<endl;
	    break;
     case 4:cout<<thousand<<","<<hundred<<","<<ten<<","<<indiv<<endl;
	    cout<<"reverse order:";
	    cout<<indiv<<ten<<hundred<<thousand<<endl;
	    break;
     case 3:cout<<hundred<<","<<ten<<","<<indiv<<endl;
	    cout<<"reverse order:";
	    cout<<indiv<<ten<<hundred<<endl;
	    break;
     case 2:cout<<ten<<","<<indiv<<endl;
	    cout<<"reverse order:";
	    cout<<indiv<<ten<<endl;
	    break;
     case 1:cout<<indiv<<endl;
	    cout<<"reverse order:";
	    cout<<indiv<<endl;
	    break;
  }
  return 0;
}		  