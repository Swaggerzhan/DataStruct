#include <iostream>


using namespace std;

// 0 1 2 3 4 5 6 7 
// 1 2 3 4 5 6 7 0
// 6 7 0 1 2 3 4 5



class Solution {
public:
    int search(vector<int>& nums, int target) {
    	

    	int n = nums.size();
    	if (!n)
    		return -1;
    	if (n == 1){
    		if (nums[0] == target)
    			return target;
    		return -1;
    	}
    	int l = 0;
    	int r = n-1;

    	while (l <= r){
    		int mid = (l + r) / 2;
    		/* 如果发现小于，则左区间必定有序 */
    		if (nums[mid] == target)
    			return mid;
    		if (nums[0] <= nums[mid]){
    			/* 左区间中是可以找到target的，就到左区间中寻找 */
    			if (target >= nums[0] && target < nums[mid]){
    				r = mid;
    			}else{ // 左区间不满足，到右区间中寻找
    				l = mid + 1;
    			}
    		}else {
    			/* 如果情况不是左区间有序，那就是右区间有序咯，那先试试右边 */
    			if (target > nums[mid] && target <= nums[r]){
    				l = mid + 1;
    			}else{
    				r = mid - 1;
    			}
    		}
    	}		
    	return -1;

    }


   
};



int main(){

	Solution s;
	std::vector<int> v = {4, 5, 6, 7, 0, 1, 2};
	s.search(v, 0);
}

