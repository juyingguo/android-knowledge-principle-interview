/**
————————————————
版权声明：本文为CSDN博主「简渲」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/tianzry/article/details/61933362
*/
#include <stdio.h>
#include <windows.h>
#include <process.h>

int a = 0; //全局变量

//自定义的函数，在新的线程中执行
void fun1(/*void * */){//形参void * 不可省略，否则编译出错.// 不同编译器，有的需要有的不需要。
        while(1){
        a++;
        if(a>=10) break;

        Sleep(200);
        printf("a = %d, new thread running...\n", a);
    }
    printf("new thread end.\n\n");
    _endthread();
}
int main(){
    _beginthread(fun1,0,NULL);
    while(1){
        if(a >= 10){
            printf("main thread execute finish.\n");
            break;
        }
    }
    return 0;
}

