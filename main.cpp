#include <iostream>
#include "Graph/denseGraph.h"

using std::endl;
using std::cout;

int main(int argc, char** args) {

//    LRU lRUCache(2);
//    lRUCache.put(1, 1); // 缓存是 {1=1}
//    lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//    cout << lRUCache.get(1) << endl;    // 返回 1
//    lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//    cout << lRUCache.get(2) << endl;    // 返回 -1 (未找到)
//    lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//    cout << lRUCache.get(1) << endl;    // 返回 -1 (未找到)
//    cout << lRUCache.get(3) << endl;    // 返回 3
//    cout << lRUCache.get(4) << endl;    // 返回 4

    DenseGraph(10, false);

}
