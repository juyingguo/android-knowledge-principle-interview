/**

��Ȩ����������ΪCSDN���������֡���ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/tianzry/article/details/61933362

*/

#include <stdio.h>
#include <windows.h>
#include <process.h>

int a = 0; //ȫ�ֱ���

void fun2(void *pArg){
    printf("main thread pass argument%d\n\n", *(int *)pArg);
    a = *(int *)pArg;
    while(1){
        a++;
        if(a>=10) break;
        Sleep(200);
        printf("a = %d, thead running...\n", a);
    }
    printf("new thread end.\n\n");
    _endthread();
}

int main(){
    int b = 6;
    int* arg = &b;
    _beginthread(fun2, 0, (void *)arg);
    while(1){
        if(a >= 10){
            printf("main thread execute finish\n");
            break;
        }
        //Sleep(300);
	}
    return 0;
}

