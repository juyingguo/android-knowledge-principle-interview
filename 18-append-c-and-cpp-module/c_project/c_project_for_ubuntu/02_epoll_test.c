/**
build:
    gcc epoll.c -lpthread
run:
    ./a.out
    main enter while.
    thread_loop:thread_1
    [1526290930077129] write num=2
    [1526290930077147] get poll data[1/1],events:1,num:2
    [1526290935077602] write num=3
    [1526290935077649] get poll data[1/1],events:1,num:3
    [1526290940079050] write num=4
    [1526290940079100] get poll data[1/1],events:1,num:4
————————————————
版权声明：本文为CSDN博主「HelenXR」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/dabenxiong666/article/details/80317333
*/

#include <stdio.h>
#include <pthread.h>
#include <sys/eventfd.h>
#include <sys/epoll.h>
#include <inttypes.h>
#include <sys/time.h>
#define EPOLL_MAX_SIZE        50

#define RET_ERROR_RETURN(x)    \
if(ret)                \
{                \
  printf("%s:error ret = %d\n",x,ret); \
  return -1;                    \
}                              \

int g_event_fd = -1;
void *thread_loop(void* param){
  uint64_t num = 2;
  struct timeval tv;
  printf("thread_loop:%s\n",(char *)param);
  while(1){
    if(g_event_fd < 0){
        printf("%s:g_event_fd < 0,wait...\n",__FUNCTION__);
        sleep(1);
        continue;
    }
    //向文件描述符里写入数据
    if(write(g_event_fd,&num,sizeof(uint64_t)) != sizeof(uint64_t)){
      printf("%s:write error!\n",__FUNCTION__);    
      return ;
    }
    gettimeofday(&tv,NULL);
    printf("[%ld] write num=%"PRIu64"\n",tv.tv_sec*1000000 + tv.tv_usec,num++);    
    sleep(5);
  }
}

int main(int argc,char* argv[]){
  pthread_t thread_1,thread_2;
  struct epoll_event event,event_array[EPOLL_MAX_SIZE];
  int epoll_fd;
  int ret;
  struct timeval tv;

  //创建文件描述符
  g_event_fd =  eventfd(0,EFD_NONBLOCK | EFD_CLOEXEC);
  if(g_event_fd < 0){
    printf("g_event_fd error\n");
    return -1;
  }

  //步骤一:创建epoll
  epoll_fd = epoll_create(EPOLL_MAX_SIZE);
  if(epoll_fd < 0){
    printf("epoll fd error\n");
    return -1;
  }
  event.events = EPOLLIN;
  event.data.fd = g_event_fd;
  //步骤二:将文件描述符添加到epoll当中.
  if(epoll_ctl(epoll_fd,EPOLL_CTL_ADD,g_event_fd,&event) < 0){
    printf("epoll ctl:add g_event_fd error");
    return -1;
  }
  ret = pthread_create(&thread_1,NULL,thread_loop,"thread_1");
  if(ret){
    printf("create thread_1 error\n");
    return -1;
  }
  printf("main enter while.\n");
  while(1){
    //步骤三:开始监听该文件描述符
    int event_count = epoll_wait(epoll_fd,event_array,EPOLL_MAX_SIZE,-1); 
    if(event_count == -1){
    printf("epoll_wait error\n");
        return -1;
    }else if (event_count == 0){
      printf("epoll_wait: time out.\n");
    }
    int i;
    uint64_t num;
    for(i=0;i<event_count;i++){
    if(event_array[i].data.fd == g_event_fd){
          if(read(g_event_fd,&num,sizeof(uint64_t)) != sizeof(uint64_t)){
            printf("read:error\n");
            return -1;
          }
            gettimeofday(&tv,NULL);
            printf("[%ld] get poll data[%d/%d],events:%"PRIu32",num:%"PRIu64"\n",tv.tv_sec*1000000 + tv.tv_usec,i+1,event_count,event_array[i].events,num);
          }else{
            printf("epoll:warning get other fd(%d)\n",event_array[i].data.fd);
          }
    }
  }

  ret = pthread_join(thread_1,NULL);
  RET_ERROR_RETURN("thread_1 join");
  close(g_event_fd);
  close(epoll_fd);
  printf("main:end\n");
  return 0;
}

