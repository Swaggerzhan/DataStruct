#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        return quickSort3Ways(nums, 0, nums.size()-1, nums.size() - k);

    }


    int quickSort3Ways(vector<int>& nums, int l, int r, int target){

        std::cout << "l: " << l << std::endl;
        std::cout << "r: " << r << std::endl;
        std::cout << std::endl;
        if ( l > r )
            return -1;

        int rand_piv = l + ( rand() % ( r - l + 1));
        int lt = l;
        int rt = r + 1;
        int index = l + 1;
        std::swap(nums[lt], nums[rand_piv]);
        int piv = nums[l];

        while ( index < rt ){
            if (nums[index] == piv){
                index ++;
            }else if ( nums[index] < piv ){
                std::swap( nums[index], nums[lt + 1]);
                lt ++;
                index ++;
            } else {
                std::swap( nums[index], nums[rt - 1]);
                rt --;
            }
        }
        std::swap( nums[lt], nums[l]);
        if ( lt <= target && target < rt )
            return nums[target];

        if ( target >= rt )
            return quickSort3Ways(nums, rt, r, target);
        else
            return quickSort3Ways(nums, l, lt - 1, target);


    }
};