#include <iostream>
#include <fstream>
using namespace std;
struct staff
{int num;
 char name[20];
 int age;
 double  pay;
};
int main()
{staff staf[7]={2101,"Li",34,1203,2104,"Wang",23,674.5,2108,"Fun",54,778,
                  3006,"Xue",45,476.5,5101,"Ling",39,656.6},staf1;
 fstream iofile("staff.dat",ios::in|ios::out|ios::binary);
 if(!iofile)
  {cerr<<"open error!"<<endl;
   abort();
  }
 int i,m,num;
 cout<<"Five staff :"<<endl;
 for(i=0;i<5;i++)
   {cout<<staf[i].num<<" "<<staf[i].name<<" "<<staf[i].age<<" "<<staf[i].pay<<endl;
    iofile.write((char *)&staf[i],sizeof(staf[i]));}
 cout<<"please input data you want insert:"<<endl;
 for(i=0;i<2;i++)
   {cin>>staf1.num>>staf1.name>>staf1.age>>staf1.pay;
    iofile.seekp(0,ios::end);
    iofile.write((char *)&staf1,sizeof(staf1));}
  iofile.seekg(0,ios::beg);
  for(i=0;i<7;i++)
   {iofile.read((char *)&staf[i],sizeof(staf[i]));
    cout<<staf[i].num<<" "<<staf[i].name<<" "<<staf[i].age<<" "<<staf[i].pay<<endl;
   }
 bool find;
 cout<<"enter number you want search,enter 0 to stop.";
 cin>>num;
 while(num)
 {find=false;
  iofile.seekg(0,ios::beg);
  for(i=0;i<7;i++)
   {iofile.read((char *)&staf[i],sizeof(staf[i]));
    if(num==staf[i].num)
     {m=iofile.tellg();
      cout<<num<<" is No."<<m/sizeof(staf1)<<endl;
      cout<<staf[i].num<<" "<<staf[i].name<<" "<<staf[i].age<<" "<<staf[i].pay<<endl;
      find=true;
      break;
     }
   }
  if(!find)
    cout<<"can't find "<<num<<endl;
  cout<<"enter number you want search,enter 0 to stop.";
  cin>>num;
 }
  iofile.close();
  return 0;
}


