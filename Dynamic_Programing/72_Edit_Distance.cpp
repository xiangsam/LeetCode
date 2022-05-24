/*
 * @Author: Samrito
 * @Date: 2022-05-24 10:20:35
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-24 10:29:50
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; ++i) {
      for (int j = 0; j <= len2; ++j) {
        if (i == 0) {
          dp[0][j] = j;
        } else if (j == 0) {
          dp[i][0] = i;
        } else {
          if (word1[i - 1] == word2[j - 1]) {
            dp[i][j] = dp[i - 1][j - 1];
          } else {
            dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
          }
        }
      }
    }
    return dp[len1][len2];
  }
};