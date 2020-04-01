#include <iostream>
#include <cstring>
using namespace std;
int main()
 {void swap(char *,char *);
  char str1[20],str2[20],str3[20];
  cout<<"input three line:"<<endl;
  gets(str1);
  gets(str2);
  gets(str3);
  if(strcmp(str1,str2)>0)  swap(str1,str2);
  if(strcmp(str1,str3)>0)  swap(str1,str3);
  if(strcmp(str2,str3)>0)  swap(str2,str3);
  cout<<endl<<"Now,the order is:"<<endl;
  cout<<str1<<endl<<str2<<endl<<str3<<endl;
  return 0;
 }
 void swap(char *p1,char *p2)          /* ½»»»Á½¸ö×Ö·û´® */
 {char p[20];
  strcpy(p,p1);strcpy(p1,p2);strcpy(p2,p);
 }



 
