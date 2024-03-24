/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX); //记录所需最小硬币数
        dp[0] = 0;
        for(int target = 1; target <= amount; ++target){
            for(const auto & coin : coins){
                if(target - coin >= 0 && dp[target - coin] != INT_MAX){
                    dp[target] = min(dp[target], dp[target - coin] + 1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1: dp[amount];
    }
};
// @lc code=end

