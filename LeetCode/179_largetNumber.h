//
// Created by swagger on 2021/5/2.
//

#ifndef DATASTRUCT_179_LARGETNUMBER_H
#define DATASTRUCT_179_LARGETNUMBER_H

#include "utility.h"


class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (nums[0] == 0)
            return "0";
        std::string ret;
        for (int &x : nums){
            ret += to_string(x);
        }
        return ret;
    }


    /* 如果返回的是true表示这样放就是最优秀解，否则就交换位子 */
    static bool cmp(const int left, const int right){
        int left_bit = 10, right_bit = 10;
        while (left_bit <= left)
            left_bit *= 10;
        while (right_bit <= right)
            right_bit *= 10;

        if ((right_bit * left + right) > (left_bit * right + left))
            return true;
        return false;

    }

};



#endif //DATASTRUCT_179_LARGETNUMBER_H
