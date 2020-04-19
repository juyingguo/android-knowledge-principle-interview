
#include "utility.h"

int main(int argc, char *argv[])
{
    //服务器IP + port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = PF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    //创建监听socket
    int listener = socket(PF_INET, SOCK_STREAM, 0);
    if(listener < 0) { perror("listener"); exit(-1);}
    printf("listen socket created \n");
    printf("listener = %d\n",listener);
    //绑定地址
    if( bind(listener, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("bind error [bind socket listener to socket address error.] \n");
        perror("bind error");
        exit(-1);
    }
    printf("bind success \n");
    //监听
    int ret = listen(listener, 5);
    if(ret < 0) { perror("listen error"); exit(-1);}
    printf("Start to listen: %s\n", SERVER_IP);
    //在内核中创建事件表
    int epfd = epoll_create(EPOLL_SIZE);
    if(epfd < 0) { perror("epfd error"); exit(-1);}
    printf("epoll created, epollfd = %d\n", epfd);
    static struct epoll_event events[EPOLL_SIZE];
    //往内核事件表里添加事件
    addfd(epfd, listener, true);
    //主循环
    while(true)
    {
        //epoll_events_count表示就绪事件的数目
        int epoll_events_count = epoll_wait(epfd, events, EPOLL_SIZE, -1);
        if(epoll_events_count < 0) {
            perror("epoll failure");
            break;
        }

        printf("epoll_events_count = %d\n", epoll_events_count);
        //处理这epoll_events_count个就绪事件
        for(int i = 0; i < epoll_events_count; ++i)
        {
            int sockfd = events[i].data.fd;
            printf("current i = %d,sockfd = %d \n",i, sockfd);
            //新用户连接
            if(sockfd == listener)
            {
                struct sockaddr_in client_address;
                socklen_t client_addrLength = sizeof(struct sockaddr_in
                int clientfd = accept( listener, ( struct sockaddr* )&client_address, &client_addrLength

                printf("client connection from: %s : % d(IP : port), clientfd = %d \n",
                inet_ntoa(client_address.sin_addr),
                ntohs(client_address.sin_port),
                clientfd);

                addfd(epfd, clientfd, true);////把这个新的客户端添加到内核事件列表

                // 服务端用list保存用户连接
                clients_list.push_back(clientfd);
                printf("Add new clientfd = %d to epoll\n", clientfd);
                printf("Now there are %d clients int the chat room\n", (int)clients_list.size());

                // 服务端发送欢迎信息
                printf("welcome message\n");
                char message[BUF_SIZE];
                bzero(message, BUF_SIZE);
                sprintf(message, SERVER_WELCOME, clientfd);
                int ret = send(clientfd, message, BUF_SIZE, 0);
                if(ret < 0) { perror("send error"); exit(-1); }
            }
            //客户端唤醒//处理用户发来的消息，并广播，使其他用户收到信息
            else
            {
                int ret = sendBroadcastmessage(sockfd);
                if(ret < 0) { perror("error");exit(-1); }
            }
        }
    }
    close(listener); //关闭socket
    close(epfd);    //关闭内核   不在监控这些注册事件是否发生
    return 0;
}

