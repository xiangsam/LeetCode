/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int days = prices.size();
        if(days < 2){
            return 0;
        }
        if(k * 2 >= days){
            int benifit = 0;
            for(int i = 1; i < days; ++i){
                if(prices[i] > prices[i-1]){
                    benifit += prices[i] - prices[i-1];
                }
            }return benifit;
        }
        else{
            vector<int> buy(k+1, INT_MIN), sell(k+1, 0);
            for(int i = 0; i < days; ++i){
                for(int j = 1; j <= k; ++j){
                    buy[j] = max(buy[j], sell[j-1] - prices[i]);
                    sell[j] = max(sell[j], buy[j] + prices[i]);
                }
            }return sell.back();
        }
    }
};
// @lc code=end

