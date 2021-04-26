/*
const_cast
*/
#include <iostream>

using namespace std;
void print(char *p);
int main() {
    char * tmp = const_cast<char*>("QUIT\r\n");

    print(tmp);

    tmp = "hello";
    print(tmp);


}

void print(char *p){
    if(p == NULL) return;

    cout<<p<<endl;
}
