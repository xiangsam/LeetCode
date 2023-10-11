/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }
        /* 无压缩
        vector<int> dp(size, 0);
        int max_sum = nums[0];
        dp[0] = nums[0];
        for(int i = 1; i < size; ++i){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
            max_sum = max(dp[i], max_sum);
        }
        return max_sum;
        */
        int dp = nums[0];
        int max_sum = dp;
        for(int i = 1; i < size; ++i){
            dp = max(nums[i], dp+nums[i]);
            max_sum = max(dp, max_sum);
        }
        return max_sum;

    }
};
// @lc code=end

