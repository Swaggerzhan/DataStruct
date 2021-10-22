//
// Created by Swagger on 2021/10/22.
//

#ifndef DATASTRUCT_QUICKSORT_H
#define DATASTRUCT_QUICKSORT_H
#include <iostream>

void quickSort(int arr[], int l, int r){
    if ( l >= r )
        return;
    int rand_index_piv = rand() % ( r - l + 1) + l;
    std::swap(arr[l], arr[rand_index_piv]);
    int piv = arr[l];
    int index = l + 1;
    int lt = l;
    int rt = r + 1;
    while ( index < rt ) {
        if ( arr[index] == piv ) {
            index ++;
        }else if ( arr[index] < piv ){
            std::swap(arr[lt + 1], arr[index]);
            index ++;
            lt ++;
        }else {
            std::swap( arr[rt - 1], arr[index]);
            rt --;
        }
    }
    std::swap( arr[l], arr[lt]);
    quickSort(arr, l, lt - 1);
    quickSort(arr, rt, r);
}

#endif //DATASTRUCT_QUICKSORT_H
