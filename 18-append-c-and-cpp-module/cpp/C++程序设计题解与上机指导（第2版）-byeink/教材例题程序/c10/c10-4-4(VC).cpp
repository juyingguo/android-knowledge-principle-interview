//������������VC++ 6.0
#include <iostream.h>
#include <string.h>
class String
 {public:
   String(){p=NULL;}
   String(char *str);
   friend bool operator>(String &string1,String &string2);
   friend bool operator<(String &string1,String &string2);
   friend bool operator==(String &string1,String &string2);
  void display();
  private:
   char *p;
 };
 
String::String(char *str)
{p=str;
}

void String::display()
 {cout<<p;}
 
bool operator>(String &string1,String &string2)
{if(strcmp(string1.p,string2.p)>0)
   return true;
 else
   return false;
}

bool operator<(String &string1,String &string2)
{if(strcmp(string1.p,string2.p)<0)
   return true;
 else
   return false;
}

bool operator==(String &string1,String &string2)
{if(strcmp(string1.p,string2.p)==0)
   return true;
 else
   return false;
}

void compare(String &string1,String &string2)
{if(operator>(string1,string2)==1)
  {string1.display();cout<<">";string2.display();}
 else
  if(operator<(string1,string2)==1)
   {string1.display();cout<<"<";string2.display();}
 else
  if(operator==(string1,string2)==1)
   {string1.display();cout<<"=";string2.display();}
 cout<<endl;
}

int main()
{String string1("Hello"),string2("Book"),string3("Computer"),string4("Hello");
 compare(string1,string2);
 compare(string2,string3);
 compare(string1,string4);
 return 0;
}

