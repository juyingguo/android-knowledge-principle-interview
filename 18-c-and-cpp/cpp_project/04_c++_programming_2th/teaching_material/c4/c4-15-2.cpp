//file2.cpp
//加上extern是外部函数，如果省略extern默认为外部函数
extern int max(int x,int y)
{
 int z;
 z=x>y?x:y;
 return z;
 }
