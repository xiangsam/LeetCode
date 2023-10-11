/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }
        vector<int> dp1(size, 0), dp2(size, 0);
        dp1[0] = nums[0];
        dp1[1] = dp1[0];
        dp2[1] = nums[1];
        for(int i = 2; i < size-1; ++i){
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i]);
        }
        dp1[size-1] = dp1[size-2];
        for(int i = 2; i < size; ++i){
            if(i == 2){
                dp2[i] = dp2[i-1];
            }
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
        }
        return max(dp1[size-1], dp2[size-1]);
        
    }
};
// @lc code=end

