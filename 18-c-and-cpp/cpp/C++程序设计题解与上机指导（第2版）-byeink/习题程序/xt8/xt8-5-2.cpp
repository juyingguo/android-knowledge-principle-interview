//xt8-5-2.cpp(arraymax.cpp)
#include <iostream>
using namespace std;
#include "xt8-5.h"
void Array_max::set_value()
 { int i;
   for (i=0;i<10;i++)
     cin>>array[i];
 }

void Array_max::max_value()
 {int i;
  max=array[0];
  for (i=1;i<10;i++)
   if(array[i]>max) max=array[i];
  }

void Array_max::show_value()
 {cout<<"max="<<max<<endl;
 }

