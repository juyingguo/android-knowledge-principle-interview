#include <iostream>
#include <string>

using namespace std;
// same typename
template <class T>
inline const T& Max (const T& a, const T & b)
{
    return a < b ? b:a;
}
int main ()
{

    int i = 80;
    int j = 50;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "aim";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;

   return 0;
}

