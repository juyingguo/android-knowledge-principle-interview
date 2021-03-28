#include <stdio.h>
#include "head_test.h"

/*static*/ char a = 'A'; // 默认global variable。加上static为静态全局变量,但此时只能在本c源文件范围内使用。
void msg()
{
 printf("msg(),Hello\n");
}
