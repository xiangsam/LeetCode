/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices, int fee) {
    int n = prices.size();
    vector<int> buy(n, 0), s1(n, 0), sell(n, 0), s2(n, 0);
    buy[0] = s1[0] = -prices[0];
    for (int i = 1; i < n; ++i) {
      buy[i] = max(s2[i - 1] - prices[i], sell[i - 1] - prices[i]);
      s1[i] = max(buy[i - 1], s1[i - 1]);
      sell[i] = max(buy[i - 1] + prices[i] - fee, s1[i - 1] + prices[i] - fee);
      s2[i] = max(sell[i - 1], s2[i - 1]);
    }
    return max(sell[n - 1], s2[n - 1]);
  }
};
// @lc code=end
