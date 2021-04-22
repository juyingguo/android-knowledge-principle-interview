#ifndef UDP_H
#define UDP_H

int socket_send(const char *IP);
int socket_recv();
//确的告诉c++编译器，这是一个用c语言编译的函数·你就不要把函数名转化为C++格式了

#endif // UDP_H
