/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findLongestChain1(vector<vector<int>> &pairs) { // dp
    sort(pairs.begin(), pairs.end());
    int n = pairs.size();
    vector<int> dp(n, 1);
    int max_chain = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (pairs[j][1] < pairs[i][0]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      max_chain = max(max_chain, dp[i]);
    }
    return max_chain;
  }
  int findLongestChain(vector<vector<int>> &pairs) { // 贪心
    sort(pairs.begin(), pairs.end());
    // for (auto &e : pairs) {
    //   cout << e[0] << e[1] << " ";
    // }
    int n = pairs.size();
    int max_chain = 1;
    int left = pairs[0][0], right = pairs[0][1];
    for (int i = 1; i < n; ++i) {
      if (left == pairs[i][0]) {
        right = min(pairs[i][1], right);
      } else {
        if (right < pairs[i][0]) {
          left = pairs[i][0];
          right = pairs[i][1];
          max_chain += 1;
        }
        if (right > pairs[i][1]) {
          left = pairs[i][0];
          right = pairs[i][1];
        }
      }
    }
    return max_chain;
  }
};
// @lc code=end
