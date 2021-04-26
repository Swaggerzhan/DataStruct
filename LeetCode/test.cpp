#include <iostream>


using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	std::cout << findBigest(nums) << std::endl;
    	return -1;
    }


    int findBigest(vector<int>& nums){
    	int l = 0;
    	int r = nums.size() - 1;
    	int mid = (l + r) / 2;
    	while (l != r){
    		/* 如果中间值比左边大，就往右边找 */
    		if (nums[mid] > nums[l]){		
    			l = mid;
    			mid = (l + r) / 2;
    			continue;
    		/* 如果中间值比左边小，就往左边找 */	
    		}else if (nums[mid] > nums[l]){
    			r = mid;
    			mid = (l + r) / 2;
    			continue;
    		}else{

    		}
    	}
    	return l;
    }
};



int main(){

	Solution s;
	std::vector<int> v = {4, 5, 6, 7, 0, 1, 2};
	s.search(v, 0);
}

