//
// Created by Swagger on 2021/10/27.
//

#ifndef DATASTRUCT_RINGBUFFER_H
#define DATASTRUCT_RINGBUFFER_H
#include <atomic>

class RingBuffer{
public:
    RingBuffer(int capacity)
    :   capacity_(capacity)
    ,   writeIndex_(0)
    ,   oldWriteIndex_(0)
    ,   readIndex_(0)
    {
        data_ = new int[capacity_];
    }

    ~RingBuffer(){
        delete data_;
    }

    bool put(int target){
        int writeIndex;
        int readIndex;
        do{
            writeIndex = writeIndex_.load();
            readIndex = readIndex_.load();
            if ( (writeIndex + 1) % capacity_ == readIndex ) {
                //std::cout << "put" << std::endl;
                return false;
            }
            // do count;

        }while ( !writeIndex_.compare_exchange_weak(writeIndex, writeIndex + 1));

        data_[ (writeIndex+1) % capacity_] = target;

        while ( !oldWriteIndex_.compare_exchange_weak(writeIndex, writeIndex+1));
        return true;
    }

    int get(){
        int readIndex;
        int oldWriteIndex;
        do{
            readIndex = readIndex_.load();
            oldWriteIndex = oldWriteIndex_.load();
            if ( (readIndex + 1) % capacity_ == oldWriteIndex )
                return -1;
        }while ( !readIndex_.compare_exchange_weak(readIndex, readIndex + 1));
        int ret = data_[readIndex % capacity_];
        return ret;
    }


private:

    int* data_;
    int capacity_;
    std::atomic<int> readIndex_;
    std::atomic<int> writeIndex_;
    std::atomic<int> oldWriteIndex_;

};

#endif //DATASTRUCT_RINGBUFFER_H
