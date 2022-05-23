/*
 * @Author: Samrito
 * @Date: 2022-05-23 15:11:35
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-23 15:20:52
 */
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX - 1);
    dp[0] = 0;
    const int length = coins.size();
    for (int i = 1; i <= amount; ++i) {
      for (int j = 0; j < length; ++j) {
        if (i >= coins[j]) {
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return (dp[amount] == INT_MAX - 1) ? -1 : dp[amount];
  }
};