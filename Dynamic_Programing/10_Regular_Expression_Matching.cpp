/*
 * @Author: Samrito
 * @Date: 2022-05-26 08:59:02
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-26 10:53:07
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
  bool isMatch(string s, string p) {
    int len1 = s.length();
    int len2 = p.length();
    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= len2; ++i) {
      if (p[i - 1] == '*') {
        dp[0][i] = dp[0][i - 2];
      }
    }
    for (int i = 1; i <= len1; ++i) {
      for (int j = 1; j <= len2; ++j) {
        if (p[j - 1] == '.') {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (p[j - 1] != '*') {
          dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
        } else if (p[j - 2] != s[i - 1] &&
                   p[j - 2] != '.') { // *，但是*前的字符不是'.'也不是s[i-1]
          dp[i][j] = dp[i][j - 2];
        } else {
          dp[i][j] = dp[i][j - 1] || dp[i - 1][j] ||
                     dp[i][j - 2]; //*分别表示前一个字符出现1次，
                                   //前一个字符为.或重复，前一个字符出现0次
        }
      }
    }
    return dp[len1][len2];
  }
};