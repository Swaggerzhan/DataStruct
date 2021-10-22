//
// Created by Swagger on 2021/10/22.
//

#ifndef DATASTRUCT_MERGESORT_H
#define DATASTRUCT_MERGESORT_H

#include <iostream>


void merge(int arr[], int l, int mid, int r){
    int tmp[ r - l + 1];
    for ( int i=l; i <=r; i++)
        tmp[i-l] = arr[i];

    int left = l;
    int right = mid + 1;
    for (int index=l; index <=r; index ++) {
        if ( left > mid ){
            arr[index] = tmp[right - l];
            right ++;
        }else if ( right > r ){
            arr[index] = tmp[left - l];
            left ++;
        // 以上是前置条件
        }else if ( tmp[left - l] < tmp[right - l]) {
            arr[index] = tmp[left - l];
            left ++;
        }else {
            arr[index] = tmp[right - l];
            right ++;
        }
    }

}

void mergeSort(int arr[], int l, int r){
    if (l >= r)
        return;
    int mid = l + (( r - l) / 2);
    //int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}


#endif //DATASTRUCT_MERGESORT_H
