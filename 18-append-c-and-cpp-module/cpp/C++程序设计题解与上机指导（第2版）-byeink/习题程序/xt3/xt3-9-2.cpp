#include <iostream>
using namespace std;
int main ( )
  {int a,b,c,temp,max ;
   cout<<"please enter three integer numbers:";
   cin>>a>>b>>c;
   temp=(a>b)?a:b;                 /*  ��a��b�еĴ��ߴ���temp�� */
   max=(temp>c)?temp:c;            /*  ��a��b�еĴ�����c�Ƚϣ�����ߴ���max */
   cout<<"max="<<max<<endl;
   return 0;
  }

