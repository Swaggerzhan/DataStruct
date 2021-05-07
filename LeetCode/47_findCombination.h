#include <iostream>
#include <vector>



class Solution{

private:

	vector<vector<int>> ret;

	vector<bool> used;

	void findCombiation(vector<int>&nums, vector<int>&tmp_ans){

		if (tmp_ans.size() == nums.size()){
			ret.push_back(tmp_ans);
			return;
		}


		for (int i=0; i<nums.size(); i++){

			/* 进行剪枝操作 */
			if ( i > 0 && nums[i] == nums[i-1] && used[i-1] == false)
				continue;

			if ( used[i] == false){
				tmp_ans.push_back(nums[i]);
				used[i] = true;
				findCombiation(nums, tmp_ans);
				used[i] = false;
				tmp_ans.pop_back();
			}
		}
	}





public:

	vector<vector<int>> permuteUnique(vector<int>&nums){
		used = vector<bool>(nums.size(), false);
		vector<int> tmp_ans;
		findCombiation(nums, tmp_ans);
		return ret;
	}

};