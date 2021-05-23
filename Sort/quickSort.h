//
// Created by swagger on 2021/5/23.
//

#ifndef DATASTRUCT_QUICKSORT_H
#define DATASTRUCT_QUICKSORT_H

#include <algorithm>
#include "sortHelper.h"


namespace sort
{

    int __quickSort(std::vector<int>& arr, int l, int r){
        //随机基准点
        int rand_piv = l + (rand() % (r - l + 1));
        std::swap(arr[l], arr[rand_piv]);
        int piv = arr[l];
        int diff = l;
        for (int i=l+1; i<=r; i++){
            if (arr[i] < piv){
                std::swap(arr[diff+1], arr[i]);
                diff ++;
            }
        }
        std::swap(arr[diff], arr[l]);
        return diff;
    }

    void _quickSort(std::vector<int>& arr, int l, int r){
        if (l >= r)
            return;
        int piv_index = __quickSort(arr, l, r);
        _quickSort(arr, l, piv_index-1);
        _quickSort(arr, piv_index+1, r);
    }


    void quickSort(std::vector<int>& arr, int len){
        std::cout << "start sorting" << std::endl;
        clock_t start_time = clock();
        _quickSort(arr, 0, len-1);
        clock_t used_time = clock() - start_time;
        std::cout << "used: " << (double )used_time / CLOCKS_PER_SEC << std::endl;
    }


};



#endif //DATASTRUCT_QUICKSORT_H
