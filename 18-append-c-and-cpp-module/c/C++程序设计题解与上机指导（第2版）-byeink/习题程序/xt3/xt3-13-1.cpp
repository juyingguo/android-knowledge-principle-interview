#include <iostream>
using namespace std;
int main ()
{ long i;                       //i为利润
  float  bonus,bon1,bon2,bon4,bon6,bon10;
  bon1=100000*0.1;             //利润为10万元时的奖金
  bon2=bon1+100000*0.075;      //利润为20万元时的奖金
  bon4=bon2+100000*0.05;       //利润为40万元时的奖金
  bon6=bon4+100000*0.03;       //利润为60万元时的奖金
  bon10=bon6+400000*0.015;     //利润为100万元时的奖金
  cout<<"enter i:"; 
  cin>>i;
  if (i<=100000)
     bonus=i*0.1;                     //利润在10万元以内按10%提成奖金
  else if (i<=200000)
     bonus=bon1+(i-100000)*0.075;    //利润在10万元至20万时的奖金
  else if (i<=400000)
     bonus=bon2+(i-200000)*0.05;     //利润在20万元至40万时的奖金
  else if (i<=600000)
     bonus=bon4+(i-400000)*0.03;     //利润在40万元至60万时的奖金
  else if (i<=1000000)
     bonus=bon6+(i-600000)*0.015;    //利润在60万元至100万时的奖金
  else
     bonus=bon10+(i-1000000)*0.01;   //利润在100万元以上时的奖金
  cout<<"bonus="<<bonus<<endl; 
  return 0;
 }
