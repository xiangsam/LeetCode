/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 *
 * [1696] 跳跃游戏 VI
 */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        deque<int> queue;// 递减队列
        dp[0] = nums[0];
        queue.emplace_back(0);// 记录位置，确保最大值在合法窗口
        for(int i = 1; i < n; ++i){
            while(!queue.empty() && queue.front() < i - k){
                queue.pop_front();
            }
            dp[i] = nums[i] + dp[queue.front()];
            while(!queue.empty() && dp[queue.back()] < dp[i]){
                queue.pop_back();
            }
            queue.emplace_back(i);
        } 
        return dp[n-1];
    }
};
// @lc code=end

