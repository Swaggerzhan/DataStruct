//
// Created by Swagger on 2021/10/26.
//

#ifndef DATASTRUCT_LOCKFREEQUEUE_H
#define DATASTRUCT_LOCKFREEQUEUE_H

#include <atomic>

struct Node{
    int val;
    std::atomic<Node*> next;
    Node(int target)
    :   val(target)
    ,   next(nullptr)
    {}
};

class Queue{
public:

    Queue();
    ~Queue();

    void puts(int target);

    int get();

private:
    std::atomic<Node*> head_;
    std::atomic<Node*> tail_;


};

#endif //DATASTRUCT_LOCKFREEQUEUE_H
