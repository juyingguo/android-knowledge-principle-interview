#include <iostream>
using namespace std;
int main()
{int i,j,upper,lower,digit,space,other;
 char text[3][80];
 upper=lower=digit=space=other=0;
 for (i=0;i<3;i++)
   {cout<<"please input line "<<i+1<<endl;
    gets(text[i]);
    for (j=0;j<80 && text[i][j]!='\0';j++)
      {if (text[i][j]>='A'&& text[i][j]<='Z')
         upper++;
       else if (text[i][j]>='a' && text[i][j]<='z')
         lower++;
       else if (text[i][j]>='0' && text[i][j]<='9')
         digit++;
       else if (text[i][j]==' ')
         space++;
       else
         other++;
     }
   }
   cout<<"upper case:"<<upper<<endl;
   cout<<"lower case:"<<lower<<endl;
   cout<<"digit     :"<<digit<<endl;
   cout<<"space     :"<<space<<endl;
   cout<<"other     :"<<other<<endl;
   return 0;
} 
