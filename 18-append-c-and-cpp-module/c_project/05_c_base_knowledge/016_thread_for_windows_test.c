/**
��������������������������������
��Ȩ����������ΪCSDN���������֡���ԭ�����£���ѭ CC 4.0 BY-SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/tianzry/article/details/61933362
*/
#include <stdio.h>
#include <windows.h>
#include <process.h>

int a = 0; //ȫ�ֱ���

//�Զ���ĺ��������µ��߳���ִ��
void fun1(/*void * */){//�β�void * ����ʡ�ԣ�����������.// ��ͬ���������е���Ҫ�еĲ���Ҫ��
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

