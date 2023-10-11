/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0, buy = INT_MAX;
        for(int i = 0; i < prices.size(); ++i){
            buy = min(buy, prices[i]);
            sell = max(sell, prices[i] - buy);
        }
        return sell;
    }
};
// @lc code=end

