#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline const T& Max (const T &a, const T & b)
{
    return a < b ? b:a;
}
template <typename T>
inline /*const*/ T& MaxTest (/*const*/ T &a, /*const*/ T & b)
{
    a = 10;
    b = 20;
    return a < b ? b:a;
}
int main ()
{

    int i = 39;
    int j = 50;
    cout << "Max(i, j): " << Max(i, j) << endl;

    int m = 39;
    int n = 50;
    cout << "MaxTest(m, n): " << MaxTest(m, n) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "A Ha";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;

   return 0;
}

