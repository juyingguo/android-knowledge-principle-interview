#include <iostream>
#include <string>
using namespace std;
template <class T1,class T2>
class Test
{
    public:
        Test();
        Test(T1 d1, T2 d2);
        template <class U,class V> Test(const Test<U,V> &t);
        void SetData1(T1 val)
        {
            data1=val;
        }
        void SetData2(T2 val)
        {
            data2=val;
        }
        T1 GetData1()
        {
            return data1;
        }
        T2 GetData2()
        {
            return data2;
        }
    private:
        T1 data1;
        T2 data2;
};


template <class T1,class T2>
Test<T1,T2>::Test() {}


template <class T1,class T2>
Test<T1, T2>::Test(T1 d1, T2 d2):
    data1(d1),data2(d2) {}


template <class T1,class T2> template <class U,class V>
Test<T1, T2>::Test(const Test<U,V> &t):
    data1(t.data1),data2(t.data2) {};


int main()
{
    Test <int,double> t1(10, 5.68);
    cout<<t1.GetData1()<<"   "<<t1.GetData2()<<endl;
    Test <int,double> t2(t1);
    cout<<t2.GetData1()<<"   "<<t2.GetData2()<<endl;
    return 0;
}
