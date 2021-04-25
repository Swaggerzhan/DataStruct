#include "LeetCode/146_LRU.h"
#include <iostream>


using std::cout;
using std::endl;


int main() {

    auto *lruCache = new LRUCache(2);

    lruCache->put(1, 1); // 缓存是 {1=1}
    lruCache->put(2, 2); // 缓存是 {1=1, 2=2}
    cout << lruCache->get(1) << endl;    // 返回 1
    lruCache->put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
    cout << lruCache->get(2) << endl;    // 返回 -1 (未找到)
    lruCache->put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
    cout << lruCache->get(1) << endl;    // 返回 -1 (未找到)
    cout << lruCache->get(3) << endl;    // 返回 3
    cout << lruCache->get(4) << endl;    // 返回 4


}
