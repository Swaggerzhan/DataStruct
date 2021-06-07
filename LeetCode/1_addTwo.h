//
// Created by swagger on 2021/6/7.
//

#ifndef DATASTRUCT_1_ADDTWO_H
#define DATASTRUCT_1_ADDTWO_H
#include <vector>
#include <map>

using std::vector;
using std::map;

class Solution{
public:

    vector<int> addTow(vector<int>& nums, int target){
        map<int, int> map_;
        for (int i=0; i<nums.size(); i++){
            int other = nums[i] - target;
            if (map_.find(other) != map_.end())
                return vector<int>{nums[i], other};
            map_.insert(std::pair<int, int>(i, nums[i]));
        }
        return vector<int>{};
    }


};



#endif //DATASTRUCT_1_ADDTWO_H
