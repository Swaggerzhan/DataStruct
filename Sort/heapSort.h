//
// Created by Swagger on 2021/8/4.
//

#ifndef DATASTRUCT_HEAPSORT_H
#define DATASTRUCT_HEAPSORT_H


/* 最小堆 */
class Heap{
public:

    Heap(int capacity)
    :   capacity_(capacity),
        size_(0)
    {
        data_ = new int[capacity_];
    }

    ~Heap(){
        delete data_;
    }

    bool insert(int target){
        if ( size_ >= capacity_ )
            return false;

        data_[size_ + 1] = target;
        shiftUp( size_ + 1 );
        size_ ++;
        return true;
    }

    bool isEmpty(){
        return size_ == 0;
    }

    int pop(){
        if ( isEmpty() )
            return -1;
        int ret = data_[1];
        std::swap(data_[1], data_[size_]);
        size_ --;
        shiftDown(1);
        return ret;
    }


private:

    void shiftUp(int index){

        while ( index > 1 && data_[index] < data_[index / 2]) {
            std::swap(data_[index], data_[index/2]);
            index /= 2;
        }
    }


    void shiftDown(int index){

        int child = index * 2;
        while (child <= size_) {

            if ( child + 1 <= size_ ){
                child = data_[child] < data_[child + 1] ? child : child + 1;
            }

            if ( data_[index] > data_[child]){
                std::swap( data_[index], data_[child]);
                index = child;
                child = index * 2;
            }else{
                break;
            }
        }

    }

private:

    int capacity_;
    int size_;

    int* data_;

};


#endif //DATASTRUCT_HEAPSORT_H
