/*
 * @Author: Samrito
 * @Date: 2022-05-22 09:32:27
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-22 10:19:44
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    int length = strs.size();
    vector<vector<vector<int>>> dp(
        length, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    int ans = 0;
    for (int i = 0; i < length; ++i) {
      int length_1 = count(strs[i].begin(), strs[i].end(), '1');
      int length_0 = count(strs[i].begin(), strs[i].end(), '0');
      if (i == 0) {
        if (length_0 <= m && length_1 <= n) {
          dp[0][length_0][length_1] = 1;
          ans = 1;
        }
      } else {
        for (int j = 0; j <= m; ++j) {
          for (int k = 0; k <= n; ++k) {
            dp[i][j][k] = dp[i - 1][j][k];
            if (j - length_0 >= 0 && k - length_1 >= 0) {
              dp[i][j][k] =
                  max(dp[i][j][k], dp[i - 1][j - length_0][k - length_1] + 1);
            }
            ans = max(ans, dp[i][j][k]);
          }
        }
      }
    }
    return ans;
  }
  //空间压缩
  int findMaxForm2(vector<string> &strs, int m, int n) {
    int length = strs.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int ans = 0;
    for (int i = 0; i < length; ++i) {
      int length_1 = count(strs[i].begin(), strs[i].end(), '1');
      int length_0 = count(strs[i].begin(), strs[i].end(), '0');
      if (i == 0) {
        if (length_0 <= m && length_1 <= n) {
          dp[length_0][length_1] = 1;
          ans = 1;
        }
      } else {
        for (int j = m; j >= length_0; --j) {
          for (int k = n; k >= length_1; --k) {
            dp[j][k] = max(dp[j][k], dp[j - length_0][k - length_1] + 1);
            ans = max(ans, dp[j][k]);
          }
        }
      }
    }
    return ans;
  }
};