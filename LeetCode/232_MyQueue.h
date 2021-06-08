//
// Created by swagger on 2021/6/8.
//

#ifndef DATASTRUCT_232_MYQUEUE_H
#define DATASTRUCT_232_MYQUEUE_H

#include <stack>

using std::stack;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue()
    :   input_(),
        output_()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        input_.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if ( output_.empty() ){
            moveIn2Out();
        }
        if ( output_.empty() )
            return -1;
        int ret = output_.top();
        output_.pop();
        return ret;
    }

    /** Get the front element. */
    int peek() {
        if ( output_.empty() ){
            moveIn2Out();
        }
        if ( output_.empty() )
            return -1;
        return output_.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return input_.empty() && output_.empty();
    }

private:

    void moveIn2Out(){
        int target = 0;
        while ( !input_.empty()){
            target = input_.top();
            input_.pop();
            output_.push(target);
        }
    }

    stack<int> input_;
    stack<int> output_;
};

#endif //DATASTRUCT_232_MYQUEUE_H
