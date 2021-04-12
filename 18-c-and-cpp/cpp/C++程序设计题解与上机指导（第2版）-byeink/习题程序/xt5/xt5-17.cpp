#include <iostream>
#include <string>
using namespace std;
const int n=10;
string name[n];
int num[n],score[n];
int main()
{int i;
 void input_data();
 input_data();
 cout<<endl<<"The list of failed:"<<endl;
 for(i=0;i<n;i++)
   if(score[i]<60)
     cout<<name[i]<<" "<<num[i]<<"  "<<score[i]<<endl;
  return 0;
}

void input_data()
{int i;
 for (i=0;i<n;i++)
   {cout<<"input name,number and score of student "<<i+1<<":";
    cin>>name[i]>>num[i]>>score[i];}
}


     
     

