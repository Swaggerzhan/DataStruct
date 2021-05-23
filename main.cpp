#include "Sort/quickSort.h"


int main(int argc, char** args) {

    std::vector<int>arr;
    int len = 100000;
    //sort::getArray(arr, len);
    sort::getArrayNearSorted(arr, len, 10);
    //sort::printArray(arr);
    sort::quickSort(arr, len);
    std::cout << sort::isSort(arr) << std::endl;


}
