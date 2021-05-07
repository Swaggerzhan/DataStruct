#include <vector>
#include <iostream>



class Solution{

private:

    vector<bool> bitMap;

    vector<vector<int>> ans;

    void findCombiation(vector<int>&nums, vector<int>& target){

        if (target.size() == nums.size()){
            ans.push_back(target);
            return;
        }
        for (int i=0; i<nums.size(); i++){

            if ( bitMap[i] == false ){
                target.push_back(nums[i]);
                bitMap[i] = true;
                findCombiation(nums, target);
                bitMap[i] = false;
                target.pop_back();
            }
        }

    }



public:
    vector<vector<int>> permute(vector<int> &nums){
        bitMap = vector<bool>(nums.size(), false);
        vector<int> target;
        findCombiation(nums, target);
        return ans;
    }
    
};