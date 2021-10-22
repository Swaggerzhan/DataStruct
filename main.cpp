#include <iostream>
#include "LeetCode/93_restoreIpAddresses.h"
#include "interview/atoi.h"
#include "interview/quicksort.h"
#include "interview/mergeSort.h"

using std::endl;
using std::cout;
using std::string;



int main(int argc, char** args) {
    int arr[] = {10, 2, 3, 6, 1, 4, 7, 9, 8, 5};
    mergeSort(arr, 0, 9);
    for (int i=0; i<10; i++) {
        std::cout << arr[i]  << " ";
    }
    std::cout << std::endl;
}
