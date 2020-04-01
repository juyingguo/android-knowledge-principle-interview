#include <iostream>
#include <string>
using namespace std;
int main()
{void swap(string,string);
 string string1,string2,string3,temp;
 cout<<"please input three strings:";
 cin>>string1>>string2>>string3;
 if(string2>string3) {temp=string2;string2=string3;string3=temp;}
 if(string1<string2) cout<<string1<<" "<<string2<<" "<<string3<<endl;
 else if(string1<string3) cout<<string2<<" "<<string1<<" "<<string3<<endl;
 else cout<<string2<<" "<<string3<<" "<<string1<<endl;
 return 0;
}


