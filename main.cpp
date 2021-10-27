#include <iostream>
#include "LockFree/LockFreeQueue.h"
#include "LockFree/RingBuffer.h"
#include <thread>

using std::endl;
using std::cout;
using std::string;

RingBuffer r(10);

void put(){
    int i = 0;
    while (true){
       while (!r.put(i));
       i ++;
    }
}

void get(){
    int ret;
    while ( true ){
        ret = r.get();
        if ( ret != -1)
            std::cout << ret << std::endl;

    }
}
int main(int argc, char** args) {

    std::thread t1(put);
    std::thread t2(get);
    t1.join();
    t2.join();

}
