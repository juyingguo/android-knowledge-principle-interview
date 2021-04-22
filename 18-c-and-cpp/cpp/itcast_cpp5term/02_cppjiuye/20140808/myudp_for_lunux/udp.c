#include <stdio.h>
#include <string.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SOCKET int
int socket_send(const char *IP){

    //初始化socket完成
    //建立一个socket,第一个参数是指定socket要用那个协议,AF_INET代表要用TCP/IP协议//第二个参数SoCK_DGRAM意思是要用UDP协议
    //第三个参数一般默认填0
    SOCKET st = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in addr;
    memset (&addr,0, sizeof (addr));//初始化结构addr;
    addr.sin_family =AF_INET;//代表要使用一个TCP/IP的地址
    addr.sin_port =  htons (8088) ;//host to net short
    addr.sin_addr.s_addr = inet_addr(IP);//"127.0.0.1"

//    unsigned long laddr = inet_addr ("192.168.6.200");
//    unsigned char *p = &laddr;
//    printf("%u,%u, %u, %u\n",*(p),*(p +1),*(p +2),*(p + 3));

    char buf[1024] ={0};
    size_t rc = 0;
    while (1) {
        memset(buf,0,sizeof(buf));
        gets(buf);
        rc = sendto(st,buf,strlen(buf),0,(struct sockaddr *) &addr,sizeof(addr));
//        printf("socket_send(),sendto rc=%u.",rc);
        if(strcmp(buf,"bye") == 0){//bye 则退出
            break;
        }
    }
    close(st); //使用完socket要将其关闭
    return rc;
}
int socket_recv(){
    //初始化socket完成
    //建立一个socket,第一个参数是指定socket要用那个协议,AF_INET代表要用TCP/IP协议//第二个参数SoCK_DGRAM意思是要用UDP协议
    //第三个参数一般默认填0
    SOCKET st = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in addr;
    memset (&addr,0, sizeof (addr));//初始化结构addr;
    addr.sin_family =AF_INET;//代表要使用一个TCP/IP的地址
    addr.sin_port = htons (8088) ;//host to net short
    addr.sin_addr.s_addr= htonl(INADDR_ANY);//做为接收方﹐不需要指定具体的IP地址
    int rc = 0;
    if(bind(st,(struct sockaddr *) &addr,sizeof (addr)) >-1)//将端口号和程序绑定
    {
        char buf[1024] ={0};
        struct sockaddr_in sendaddr;
        memset ( &sendaddr, 0, sizeof (sendaddr));
        socklen_t len = sizeof(sendaddr);
        while (1) {
            memset(buf,0,sizeof(buf));
            rc = recvfrom(st, buf, sizeof(buf),0,(struct sockaddr *) &sendaddr,&len);
            //inet_ntoa (sendaddr.sin_addr);//这个函数是不可重入函数
            printf("socket_recv(),receive from ip %s :%s \n",inet_ntoa(sendaddr.sin_addr),buf);
            if(strcmp(buf,"bye") == 0){//bye 则退出
                break;
            }
        }
    }else {
        printf("socket_recv(),bind return <= -1,fail.\n");
    }
    close(st);
    return rc;
}

