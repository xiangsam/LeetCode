/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(const auto & coin : coins){
            for(int i = coin; i <= amount; ++i){
                dp[i] += dp[i-coin];
            }
        }return dp[amount];
    }
};
// @lc code=end

