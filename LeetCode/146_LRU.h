//
// Created by swagger on 2021/4/22.
//

#ifndef DATASTRUCT_146_LRU_H
#define DATASTRUCT_146_LRU_H

#include <map>
#include <ctime>

using std::endl;
using std::cout;

class LRUCache2 {

private:

    struct Node{
        int key;
        int data;
        struct Node* pre;
        struct Node* next;
        Node(int key, int data):key(key),data(data){
            pre = next = nullptr;
        }
    };



    std::map<int, Node*> map_; /* 哈希表，这里应该是树形实现 */

    struct Node* head_; /* 双向头节点 */

    struct Node* tail_; /* 链表尾节点 */

    int capacity; /* 总大小 */

    int count; /* 当前节点大小 */


public:

    LRUCache2(int capacity):capacity(capacity) {
        this->count = 0;
    }



    void put(int key, int value) {
        /* 节点已经存在，则更新 */
        if (get(key) != -1){
            map_.find(key)->second->data = value;
            return;
        }
        /* 未满 */
        if ( !isFull() ){
            Node* newNode = new Node(key, value);
            /* 插入表中 */
            map_.insert(std::pair<int, Node*>(key, newNode));
            /* 插入链表 */
            insert(newNode);
            return;
        }
        /* 已满 */
        pop(); // 删除最少使用节点
        put(key, value); /* 递归重新调用一次 */
    }

    int get(int key){
        auto iter = map_.find(key);
        if (iter != map_.end() ){
            update(iter->second);
            return iter->second->data;
        }
        return -1;
    }


private:


    void update(Node* target){
        /* 已经是队尾了，不进行操作 */
        if (target == tail_ )
            return;
        /* 队头，那就将其移动到队尾 */
        if (target == head_ ){
            /* 将头节点往后移动一个位置 */
            head_ = target->next;
            head_->pre = nullptr;
            /* target插入尾节点 */
            target->next = nullptr;
            tail_->next = target;
            target->pre = tail_;
            tail_ = target;
            return;
        }
        /* 队中间 */
        auto* preNode = target->pre;
        auto* nxtNode = target->next;
        preNode->next = nxtNode;
        nxtNode->pre = preNode;
        /* 加入到尾部 */
        target->next = nullptr;
        target->pre = tail_;
        tail_->next = target;
        tail_ = target;
    }


    bool isFull(){return count == capacity;}


    void insert(Node* target){
        ++ count;
        if ( !head_ ){
            head_ = tail_ = target;
            return;
        }
        /* 直接加入到尾巴节点即可 */
        target->pre = tail_;
        tail_->next = target;
        tail_ = target;
    }


    void pop(){
        auto* delNode = head_;
        head_ = head_->next;
        head_->pre = nullptr; /* 还是将指针置空安全点 */
        map_.erase(delNode->key); /* 将其从表中删除 */
        delete delNode;
        -- count;
    }


};

#include <list>

class LRU{
public:

    struct Node{
        Node(int key, int value)
        :   key(key),
            value(value),
            pre(nullptr),
            next(nullptr)
        {

        }

        int key;
        int value;

        Node* pre;
        Node* next;
    };


public:

    LRU(int capacity)
    :   capacity_(capacity),
        head_(nullptr),
        tail_(nullptr),
        size_(0)
    {

    }

    ~LRU(){
        Node* tmp = head_;
        while ( tmp ){
            if ( tmp == tail_ )
                break;
            Node* delNode = tmp;
            tmp = tmp->next;
            delete delNode;
        }
        delete tail_;
    }

    int get(int key){
        auto iter = map_.find(key);
        if ( iter == map_.end() )
            return -1;

        int ret = iter->second->value;
        update(iter->second);
        return ret;
    }

    void put(int key, int value){
        // 更新
        if ( get(key) != -1 ){
            auto iter = map_.find(key);
            iter->second->value = value;
        }else {
            Node* node = new Node(key, value);
            if ( isFull() ){ // 已满
                map_.erase(tail_->key);
                deleteNode(tail_, true);
            }
            map_.insert(std::pair<int, Node*>(key, node));
            insertToList(node);

        }
    }


    bool isFull(){
        return size_ >= capacity_;
    }

private:

    void insertToList(Node* node){
        if ( size_ == 0 ){
            head_ = node;
            tail_ = node;
        }else if ( size_ == 1 ){
            node->next = head_;
            head_->pre = node;
            head_ = node;
            tail_ = head_->next;
        }else {
            node->next = head_;
            head_->pre = node;
            head_ = node;
        }
        size_ ++;
    }

    void deleteNode(Node* node, bool del){
        if ( node == head_ ){
            head_ = head_->next;
            if (del)
                delete node;
        }else if ( node == tail_ ){
            tail_ = tail_->pre;
            if (del)
                delete node;
        }else {
            Node* preNode  = node->pre;
            Node* nextNode = node->next;
            preNode->next = nextNode;
            nextNode->pre = preNode;
            if (del)
                delete node;
        }
        size_ --;
    }

    void update(Node* node){

        if ( node == head_ )
            return;
        deleteNode(node, false);
        insertToList(node);
    }


private:

    std::map<int, Node*> map_;

    Node* head_;
    Node* tail_;
    int capacity_;
    int size_;

};









#endif //DATASTRUCT_146_LRU_H
