/*
 * @Author: Samrito
 * @Date: 2022-05-18 15:51:55
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-18 16:03:12
 */
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, INT_MAX - 1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; i - j * j >= 0; ++j) {
        dp[i] = min(dp[i - j * j] + 1, dp[i]);
      }
    }
    for (auto &e : dp) {
      cout << e << " ";
    }
    return dp[n];
  }
};