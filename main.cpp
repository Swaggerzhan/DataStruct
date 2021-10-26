#include <iostream>
#include "LockFree/LockFreeQueue.h"
#include <thread>

using std::endl;
using std::cout;
using std::string;

Queue q;

void put(){
    int i = 0;
    for (;;) {
        q.puts(i);
        i ++;
    }
}

void get(){
    for (;;) {
        int ret = q.get();
        if ( ret != -1 ){
            std::cout << ret << std::endl;
        }
    }
}


int main(int argc, char** args) {
    std::thread t1(put);
    std::thread t2(get);
    t1.join();
    t2.join();


}
