// vector::begin/end
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);
    std::vector<int>::iterator myItBegin = myvector.begin();
    std::cout << "myvector.begin() value:"<<*myItBegin<<std::endl;
    std::cout << "myvector[0] value:"<<myvector[0]<<std::endl;
   std::vector<int>::iterator myItEnd = myvector.end();
    std::cout << "myvector last value:"<<*(myItEnd-1)<<std::endl;

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
