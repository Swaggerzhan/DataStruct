//
// Created by swagger on 2021/4/22.
//

#ifndef DATASTRUCT_146_LRU_H
#define DATASTRUCT_146_LRU_H

#include <map>
#include <ctime>



class LRUCache {

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

    LRUCache(int capacity):capacity(capacity) {
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
        :   key_(key),
            value_(value),
            next(nullptr),
            pre(nullptr)
            {}

        int key_;
        int value_;

        struct Node* pre;
        struct Node* next;
    };


    LRU(int capacity)
    :   capacity_(capacity),
        size_(0)
    {

    }

    int get(int key) {
        auto it = map_.find(key);
        if ( it == map_.end() )
            return -1;
        update(it->second);
        return it->second->value_;
    }

    void put(int key, int value) {
        if ( get(key) == -1){ // 不存在，真正的put
            if ( size_ >= capacity_ ){
                auto it = map_.find(tail_->key_);
                Node* curNode = it->second;
                Node* preNode = curNode->pre;
                map_.erase(it);
                size_ --;
                /* 只有一个元素的应该没有人会搞吧? */
                preNode->next = nullptr;
                delete curNode;
            }
            size_ ++;
            Node* node = new Node(key, value);
            map_.insert( std::pair<int, Node*>(key, node));
            if ( head_ ){
                Node* tmp = head_;
                head_ = node;
                node->next = tmp;
                tmp->pre = node;
            }else {
                head_ = node;
                tail_ = node;
            }
        }else{ // 更新即可
            auto it = map_.find(key);
            it->second->value_ = value;
        }
    }

private:

    void update(Node* node){
        if (node == head_ ){
            return;
        }
        if (node == tail_ ){
            Node* preNode = tail_->pre;
            preNode->next = nullptr;
            Node* tmp = head_;
            head_ = node;
            node->next = tmp;
            tmp->pre = node;
            return;
        }
        Node* preNode = node->pre;
        Node* nextNode = node->next;
        preNode->next = nextNode;
        nextNode->pre = preNode;

        Node* tmp = head_;
        head_ = node;
        node->next = tmp;
        tmp->pre = node;
    }


private:

    std::map<int, Node*> map_;

    int capacity_;              // 总容量
    int size_;

    Node* head_;
    Node* tail_;


};









#endif //DATASTRUCT_146_LRU_H
