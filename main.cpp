#include <iostream>
#include "LeetCode/20_isValid.h"
#include "Sort/heapSort.h"

using std::endl;
using std::cout;

int main(int argc, char** args) {


    int n = 20;

    Heap heap(n);

    for (int i=0; i<n; i++){
        int rand_ = rand() % 100;
        heap.insert(rand_);
    }

    for (int i=0; i<n; i++){
        cout << heap.pop() << endl;
    }




}
