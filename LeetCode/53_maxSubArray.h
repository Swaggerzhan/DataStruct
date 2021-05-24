
#include <vector>

using namespace std;

class Solution{

public:

    vector<int> dp;

    int maxSubArray(vector<int>& nums) {
        dp.reserve(nums.size());
        dp.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++){
            dp.push_back(max(nums[i], dp[i-1]+nums[i]));
        }

        int max_ = dp[0];
        for (int i=1; i<dp.size(); i++){
            //std::cout << dp[i] << std::endl;
            max_ = max(max_, dp[i]);
        }
        return max_;
    }

};