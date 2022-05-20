/*
 * @Author: Samrito
 * @Date: 2022-05-20 09:38:05
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-20 10:28:55
 */
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    vector<vector<int>> dp(len1, vector<int>(len2, 0));

    for (int i = 0; i < len1; ++i) {
      for (int j = 0; j < len2; ++j) {
        if (i == 0) {
          if (text1[i] == text2[j]) {
            dp[i][j] = 1;
          } else {
            dp[i][j] = (j > 0) ? dp[i][j - 1] : 0;
          }
        } else if (j == 0) {
          if (text1[i] == text2[j]) {
            dp[i][j] = 1;
          } else {
            dp[i][j] = (i > 0) ? dp[i - 1][j] : 0;
          }
        } else {
          if (text1[i] == text2[j]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
          } else {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
          }
        }
      }
    }
    return dp[len1 - 1][len2 - 1];
  }
  /* 思路为转化为查找最大不相交间隔的数量，超时
  int longestCommonSubsequence(string text1, string text2) {
    int len1 = text1.length();
    int len2 = text2.length();
    vector<pair<int, int>> interval;
    for (int i = 0; i < len1; ++i) {
      for (int j = 0; j < len2; ++j) {
        if (text1[i] == text2[j]) {
          interval.emplace_back(pair<int, int>(i, j));
        }
      }
    } // 显然interval中第一个元素是从小到大排列
    int len = interval.size();
    if (len == 0) {
      return 0;
    }
    vector<int> dp(len, 0);
    int ans = 1;
    dp[0] = 1;
    for (int i = 1; i < len; ++i) {
      dp[i] = 1;
      for (int j = 0; j < i; ++j) {
        if (interval[i].first > interval[j].first &&
            interval[i].second > interval[j].second) {
          dp[i] = max(dp[i], 1 + dp[j]);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
  */
};