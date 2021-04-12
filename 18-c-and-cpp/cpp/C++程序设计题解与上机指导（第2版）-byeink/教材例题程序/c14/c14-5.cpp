//main file
#include <iostream>
#include "header11.h"
#include "header22.h"
int main()
 {Ns1::Student stud1(101,"Wang",18);
  stud1.get_data();
  cout<<Ns1::fun(5,3)<<endl;
  Ns2::Student stud2(102,"Li",'f');
  stud2.get_data();
  cout<<Ns2::fun(5,3)<<endl;
  return 0;
 }

  
