/**
https://blog.csdn.net/weixin_40997830/article/details/89402974
��δ��벻����֤�˹�����ĳ��ȣ���˵���������Ա֮����໥Ӱ�죬�޸�һ����Ա��ֵ��Ӱ��������Ա

���н����

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
