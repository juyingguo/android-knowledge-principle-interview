/**
https://blog.csdn.net/weixin_40997830/article/details/89402974
这段代码不但验证了共用体的长度，还说明共用体成员之间会相互影响，修改一个成员的值会影响其他成员

运行结果：

4, 4
40, @, 40
39, 9, 39
2059, Y, 2059
3E25AD54, T, AD54
*/
#include <stdio.h>

union data{

 int n;

 char ch;

 short m;
 long ls;
 double d;

};

int main(){

 union data a;

 printf("%d, %d\n", sizeof(a), sizeof(union data) );

 a.n = 0x40;
 printf("%X, %c, %hX\n", a.n, a.ch, a.m);

 a.ch = '9';
 printf("%X, %c, %hX\n", a.n, a.ch, a.m);

 a.m = 0x2059;
 printf("%X, %c, %hX\n", a.n, a.ch, a.m);
 a.n = 0x3E25AD54;
 printf("%X, %c, %hX\n", a.n, a.ch, a.m);
 printf("%X, %c, %lX\n", a.n, a.ch, a.ls);

 return 0;

}
