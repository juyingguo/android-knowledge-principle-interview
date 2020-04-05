#include <iostream>
using namespace std;
#define CHANGE 1
int main()
{char ch[40];
 cout<<"input text:"<<endl;;
 gets(ch);
 #if (CHANGE)
   {for (int i=0;i<40;i++)
     {if (ch[i]!='\0')
       if (ch[i]>='a'&& ch[i]<'z'||ch[i]>'A'&& ch[i]<'Z')
          ch[i]+=1;
       else if (ch[i]=='z'||ch[i]=='Z')
          ch[i]-=25;
    }
   }
 #endif
 cout<<"output:"<<endl<<ch<<endl;
 return 0;
} 


 


 
