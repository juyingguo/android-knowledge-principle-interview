#include <iostream>
//#include "udp.h"

using namespace std;

int main(int argc,char *args[])
{
    if(argc >1){
        socket_send(args[1]);
    }else {
        socket_recv();
    }
    cout << "exit!" << endl;
    return 0;
}
