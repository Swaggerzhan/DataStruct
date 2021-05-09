#include <iostream>
#include <vector>



class Solution{

private:

    void print(std::vector<int>& tmp){
        for (int i: tmp){
            std::cout << i << " ";
        }
        std::cout << endl;
    }

	vector<vector<int>> ret;

	vector<bool> used;

	void findCombiation(vector<int>&nums, vector<int>&tmp_ans){

		if (tmp_ans.size() == nums.size()){
			ret.push_back(tmp_ans);
			print(tmp_ans);
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

	void solve(){
	    int loop;
	    std::cin >> loop;
        std::vector<int> nums;
	    for (int i=0; i<loop; i++){
            int tmp;
            nums.clear();
            while (true){
                std::cin >> tmp;
                if (tmp == -1)
                    break;
                nums.push_back(tmp);
            }
	    }
        used = vector<bool>(nums.size(), false);
        vector<int> tmp_ans;
        findCombiation(nums, tmp_ans);

	}

};