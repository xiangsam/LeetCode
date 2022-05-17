/*
 * @Author: Samrito
 * @Date: 2022-05-17 10:04:37
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-17 10:29:50
 */
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
using namespace std;
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '1') {
          if (i == 0) {
            dp[0][j] = 1;
          } else if (j == 0) {
            dp[i][0] = 1;
          } else {
            dp[i][j] = 1;
            for (int target = dp[i - 1][j - 1]; target >= 1; --target) {
              if (dp[i - 1][j] >= target && dp[i][j - 1] >= target) {
                dp[i][j] = target + 1;
                break;
              }
            }
          }
        }
        // cout << dp[i][j] << ' ';
        ans = max(dp[i][j] * dp[i][j], ans);
      }
      // cout << '\n';
    }
    return ans;
  }
  int maximalSquare2(vector<vector<char>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] == '1') {
          if (i == 0) {
            dp[0][j] = 1;
          } else if (j == 0) {
            dp[i][0] = 1;
          } else {
            //其实只需要找到三个位置的最小值即可。。
            dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]});
          }
        }
        // cout << dp[i][j] << ' ';
        ans = max(dp[i][j] * dp[i][j], ans);
      }
      // cout << '\n';
    }
    return ans;
  }
};
int main() {
  Solution sol = Solution();
  vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                 {'1', '0', '1', '1', '1'},
                                 {'1', '1', '1', '1', '1'},
                                 {'1', '0', '0', '1', '0'}};
  sol.maximalSquare(matrix);
}