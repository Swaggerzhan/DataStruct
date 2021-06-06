//
// Created by swagger on 2021/6/6.
//

#ifndef DATASTRUCT_912_SORT_H
#define DATASTRUCT_912_SORT_H

#include <vector>
#include <algorithm>

class Solution {
public:

    void sort(std::vector<int>&target, int l, int r){
        if (l >= r)
            return;
        int rand_ = l + (rand() % ( r - l + 1));
        std::swap(target[l], target[rand_]);
        int lt = l;
        int rt = r + 1;
        int index = l + 1;
        int piv = target[l];
        while (index < rt){ // 小于piv情况
            if (target[index] < piv){
                std::swap(target[index], target[lt + 1]);
                index ++;
                lt ++;
            }else if (target[index] > piv){ // 大于piv情况
                std::swap(target[index], target[rt - 1]);
                rt --;
            }else{ //和piv相等情况
                index ++;
            }
        }
        std::swap(target[l], target[lt]);
        sort(target, l, lt - 1);
        sort(target, rt, r);
    }
    std::vector<int> sortArray(std::vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
    }
};

#endif //DATASTRUCT_912_SORT_H
