//
// Created by Swagger on 2021/10/26.
//
#include "LockFreeQueue.h"


Queue::Queue() {
    head_ = tail_ = new Node(-1);
}

Queue::~Queue() {

}


void Queue::puts(int target) {
    Node* node = new Node(target);
    Node* tail;
    Node* nullNode = nullptr;
    do {
        tail = tail_.load();
    }while ( !tail->next.compare_exchange_weak(nullNode, node));

    while ( !tail_.compare_exchange_weak(tail, node));

}

int Queue::get() {

    Node* head = head_.load(); //dummyHead
    Node* retNode;
    do {
        if (head->next == nullptr )
            return -1;
        retNode = head->next;
    } while ( !head->next.compare_exchange_weak(retNode, retNode->next));
    int val = retNode->val;
    delete retNode;
    return val;
}


