//本程序适用于VC++ 6.0
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
  {p=str;}

void String::display()
{cout<<p;}


bool operator>(String &string1,String &string2)
  {if(strcmp(string1.p,string2.p)>0)
    return true;
   else return false;
  }

int main()
{String string1("Hello"),string2("Book");
 cout<<(string1>string2)<<endl;
 return 0;
}

