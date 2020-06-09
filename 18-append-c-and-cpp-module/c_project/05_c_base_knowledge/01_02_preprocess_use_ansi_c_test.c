#include <stdio.h>
/**

预定义宏
    ANSI C 定义了许多宏。在编程中您可以使用这些宏，但是不能直接修改这些预定义的宏。

    宏	描述
    __DATE__	当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
    __TIME__	当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
    __FILE__	这会包含当前文件名，一个字符串常量。
    __LINE__	这会包含当前行号，一个十进制常量。
    __STDC__	当编译器以 ANSI 标准编译时，则定义为 1。


    https://www.runoob.com/cprogramming/c-preprocessors.html
*/
main()
{
   printf("File :%s\n", __FILE__ );
   printf("Date :%s\n", __DATE__ );
   printf("Time :%s\n", __TIME__ );
   printf("Line :%d\n", __LINE__ );
   printf("ANSI :%d\n", __STDC__ );

}
