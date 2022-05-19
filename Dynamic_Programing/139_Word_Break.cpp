/*
 * @Author: Samrito
 * @Date: 2022-05-19 15:25:02
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-19 15:40:46
 */
#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int sLen = s.length();
    vector<bool> dp(sLen + 1, false);
    dp[0] = true;
    for (int i = 1; i <= sLen; ++i) {
      for (auto &word : wordDict) {
        int wLen = word.length();
        if (i >= wLen && s.substr(i - wLen, wLen) == word) {
          dp[i] = dp[i - wLen] || dp[i]; //只需要找到一个word满足即可
        }
      }
    }

    return dp[sLen];
  }
};