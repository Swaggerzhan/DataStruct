//
// Created by swagger on 2021/5/23.
//

#ifndef DATASTRUCT_SORTHELPER_H
#define DATASTRUCT_SORTHELPER_H
#include <ctime>
#include <iostream>
#include <vector>


namespace sort{


    void getArray(std::vector<int>& arr, int len){

        srand(time(nullptr));
        arr.reserve(len);
        for (int i=0; i<len; i++){
            arr.push_back(rand());
        }
        std::cout << "array init ok..." << std::endl;
    }

    void getArrayNearSorted(std::vector<int>& arr, int len, int sortLevel){
        arr.reserve(len);
        for (int i=0; i<len; i++){
            arr.push_back(i);
        }
        for (int i=0; i<sortLevel; i++){
            int l = rand() % arr.size();
            int r = rand() % arr.size();
            std::swap(arr[l], arr[r]);
        }
    }


    void printArray(const std::vector<int>& arr){
        for (int tmp: arr){
            std::cout << tmp << " ";
        }
        std::cout << std::endl;
    }


    bool isSort(const std::vector<int>& arr){
        std::cout << "checking...." << std::endl;
        int pre = arr[0];
        int next;
        for (int i=1; i<arr.size(); i++){
            next = arr[i];
            if (next < pre)
                return false;
            pre = next;
        }
        return true;
    }



};



#endif //DATASTRUCT_SORTHELPER_H
