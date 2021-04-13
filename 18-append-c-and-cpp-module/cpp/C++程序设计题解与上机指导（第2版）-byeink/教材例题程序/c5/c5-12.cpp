#include <iostream>
#include <string>
using namespace std;
string name[50],num[50];
int n;
int main()
{void input_data();
 void search(string find_name);
 string find_name;
 cout<<"please input number of this class:";
 cin>>n;
 input_data();
 cout<<"please input name you want find:";
 cin>>find_name;
 search(find_name);
 return 0;
}

void input_data()
{
 int i;
 for (i=0;i<n;i++)
   {cout<<"input name and number of student "<<i+1<<":";
    cin>>name[i]>>num[i];}
}

void search(string find_name)
{int i;
 bool flag=false;
 for(i=0;i<n;i++)
   if(name[i]==find_name)
     {cout<<name[i]<<" "<<num[i]<<endl;flag=true;break;}
 if(flag==false) cout<<"can't find this name";
}
     
     

