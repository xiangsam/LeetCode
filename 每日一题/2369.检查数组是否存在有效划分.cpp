/*
 * @lc app=leetcode.cn id=2369 lang=cpp
 *
 * [2369] 检查数组是否存在有效划分
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return false;
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i){
            if(i - 2 >= 0 && dp[i - 2] == true){// case 1
                if(nums[i-2] == nums[i-1])
                    dp[i] = true;
            }if(i - 3 >= 0 && dp[i-3] == true){ // case 2 or 3
                if(nums[i-3] == nums[i-2] && nums[i-2] == nums[i-1])
                    dp[i] = true;
                if(nums[i-2] - nums[i-3] == 1 && nums[i-1] - nums[i-2] == 1)
                    dp[i] = true;
            }
        }
        return dp[n];
    }
};
// @lc code=end

