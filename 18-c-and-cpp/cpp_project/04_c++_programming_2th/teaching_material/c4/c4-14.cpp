#include <iostream>
using namespace std;
int max(int,int);
int main()
{
    //同一个文件中的全局变量，在定义前使用时，需要先使用extern声明。编译器不同，行为也可能不同。比如code:blocks 使用的gcc，没有extern也不会报错，但运行结果不是想要的，是随机的值。
    extern int a,b;
    cout<< "max(a,b)=" << max(a,b)<<endl;
    return 0;
}

int a=20,b=-8;
int max(int x,int y)
{
    int z;

    z=x>y?x:y;
    return z;
}
