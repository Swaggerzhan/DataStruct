//
// Created by swagger on 2021/6/8.
//

#ifndef DATASTRUCT_88_MERGE_H
#define DATASTRUCT_88_MERGE_H
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = nums1.size() - 1; // 尾巴
        int left = m - 1;
        int right = n - 1;
        while ( left > 0 || right > 0 ){
            if (left < 0){
                nums1[index] = nums2[right];
                right --;
                index --;
                continue;
            }
            if ( right < 0){
                nums1[index] = nums1[left];
                left --;
                index --;
                continue;
            }
            if (nums1[left] > nums2[right]) {
                nums1[index] = nums1[left];
                index --;
                left --;
            }else{
                nums1[index] = nums2[right];
                index --;
                right --;
            }
        }
    }
};

#endif //DATASTRUCT_88_MERGE_H
