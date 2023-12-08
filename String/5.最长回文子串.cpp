/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    // 回文串类问题，往往优先考虑中心扩散
    int record_len = 0;
    string ans = "";
    for (int i = 0; i < s.size(); ++i) {
      int len1 = searchPalindrome(s, i, i);
      if (len1 > record_len) {
        record_len = len1;
        ans = s.substr(i - len1 / 2, len1);
      }
      int len2 = searchPalindrome(s, i - 1, i);
      if (len2 > record_len) {
        record_len = len2;
        ans = s.substr(i - len2 / 2, len2);
      }
    }
    return ans;
  }
  int searchPalindrome(string s, int l, int r) {
    int res = -1;
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      res = r - l + 1;
      --l;
      ++r;
    }
    // cout << l << " " << r << res << endl;
    return res;
  }
  string longestPalindrome1(string s) {
    // 动态规划
    int len = s.size();
    if (len < 2) {
      return s;
    }
    vector<vector<bool>> dp(len, vector<bool>(len, false));
    int begin_s = 0, max_len = 1;
    for (int i = 0; i < len; ++i) {
      dp[i][i] = true;
    }
    for (int l = 2; l <= len; ++l) {
      for (int i = 0; i <= len - l; ++i) {
        int j = i + l - 1;
        if (s[i] != s[j]) {
          dp[i][j] = false;
        } else {
          if (j - i < 3) { // 两个字符情况
            dp[i][j] = true;
          } else {
            dp[i][j] = dp[i + 1][j - 1];
          }
        }
        if (dp[i][j] && j - i + 1 > max_len) {
          begin_s = i;
          max_len = j - i + 1;
        }
      }
    }
    return s.substr(begin_s, max_len);
  }
};
// @lc code=end
