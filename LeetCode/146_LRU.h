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
        time_t expire; /* 使用时间，交给heap管理 */

        Node(int key, int data, time_t expire):key(key), data(data), expire(expire){}
    };

    std::map<int, Node*> map_;

    int capacity; /* 总大小 */
    int count; /* 当前大小，由heap所维护即可 */
    Node **heap; /* heap所维护的数组，heap数组从1开始 */



public:

    LRUCache(int capacity) {
        this->count = 0;
        this->capacity = capacity;

    }



    void put(int key, int value) {

        /* 已经存在，则进行值替换 */
        if (get(key) != -1){
            map_.find(key)->second->data = value;
            return;
        }
        /* 新值，进行添加，已满将最久的节点删除 */
        if ( isFull() ){
            Node* delNode = pop();
            map_.erase(delNode->key);
            return;
        }
        /* 插入新元素 */
        Node* target = new Node(key, value, time(nullptr));
        map_.insert(std::pair<int, Node*>(key, target));
        /* 加入时间堆排序 */
        heap_insert(target);

    }


private:

    int get(int key) {
        auto iterator = map_.find(key);
        if (iterator == map_.end()){
            return -1;
        }
        /* 真的存在元素，则返回值并且更新使用时间 */
        heap_update(iterator->second);
        return iterator->second->data;
    }


    bool isFull(){
        return count == capacity;
    }


    Node* pop(){
        Node* ret = heap[1];
        heap_swap(&heap[1], &heap[count]);
        -- count;
        heap_shiftUp(count);
        return ret;
    }


    /**
     * 更新事件，将最近使用的元素移动到最后
     * @param target
     */
    void heap_update(Node* target){
        int idx = heap_find_index(target);
        heap_swap(&heap[idx], &heap[count]);
        /* 更新时间 */
        heap[count]->expire = time(nullptr);
        /* 将尾巴节点重新排序放到正确地方 */
        heap_shiftDown(idx);
    }


    int heap_find_index(Node* target){

    }

    /**
     * 指针交换，最好改成模版类型加以复用
     * @param left
     * @param right
     */
    void heap_swap(Node **left, Node **right){
        Node* tmp = *left;
        *left = *right;
        *right = tmp;
    }

    /**
     * 这里是不需要shiftUp的，毕竟最后添加的使用时间肯定最大
     * 只有时间最小才需要被删除(绝对时间)
     * @param target
     */
    void heap_insert(Node* target){
        heap[count + 1] = target;
        ++ count;
    }


    void heap_shiftUp(int target){
        while (target > 1){
            if (heap[target]->expire > heap[target/2]->expire)
                break;
            heap_swap(&heap[target], &heap[target/2]);
            target /= 2;
        }
    }


    void heap_shiftDown(int target){
        int k = target * 2;
        /* 当target的时间更大时才有必要继续，否则没有必要 */
        while ( k <= count && heap[target]->expire > heap[k]->expire){
            if (k + 1 <= count ){
                /* 找到子节点中最小的那个值 */
                if (heap[k+1]->expire < heap[k]->expire)
                    ++ k;
            }
            heap_swap(&heap[target], &heap[k]);
            target = k;
            k = target * 2;
        }
    }






};

#endif //DATASTRUCT_146_LRU_H
