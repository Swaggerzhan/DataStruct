//
// Created by swagger on 2021/4/7.
//

#ifndef DATASTRUCT_SORTTESTHELPER_H
#define DATASTRUCT_SORTTESTHELPER_H


#include <iostream>
#include <cstring>
#include <ctime>
#include "mergeSort.h"





int *getRandomArray(int n){

    srand(time(nullptr));
    int *ret = new int[n];
    for (int i=0; i<n; i++)
        ret[i] = (int)(rand() % 100);

    return ret;

}


void SortTest(void (*sort)(int[], int), int arr[], int n){


    sort(arr, n);
}

bool isSort(int arr[], int n){
    for (int i=0; i<n-1; i++){
        if (arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}


void SortMain(){
    int n = 1000000;
    int *arr= getRandomArray(n);

    clock_t startTime = clock();
    SortTest(mergeSort, arr, n);
    clock_t endTime = clock();
    cout << "time: " << double(endTime - startTime) / CLOCKS_PER_SEC << endl;


    if (isSort(arr, n))
        cout << "sort success!" << endl;
    else
        cout << "sort fail!" << endl;

}





#endif //DATASTRUCT_SORTTESTHELPER_H
