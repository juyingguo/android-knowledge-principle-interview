#include <fstream>
using namespace std;
void display_file(char *filename)
{ifstream infile(filename,ios::in);
 if(!infile)
  {cerr<<"open error!"<<endl;
   exit(1);}
 char ch;
 while(infile.get(ch))
   cout.put(ch);
 cout<<endl;
 infile.close();
}
int main()
{display_file("f3.dat");
 return 0;
}

