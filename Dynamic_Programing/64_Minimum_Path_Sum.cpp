/*
 * @Author: Samrito
 * @Date: 2022-05-15 10:10:42
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-15 10:24:05
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> minSum(m, vector<int>(n, 0));
    minSum[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i) {
      minSum[i][0] = grid[i][0] + minSum[i - 1][0];
    }
    for (int j = 1; j < n; ++j) {
      minSum[0][j] = grid[0][j] + minSum[0][j - 1];
    }
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; ++j) {
        minSum[i][j] = grid[i][j] + min(minSum[i - 1][j], minSum[i][j - 1]);
      }
    }
    return minSum[m - 1][n - 1];
  }

  // 空间压缩方法， 只维护一维数组表示一行上的每个位置最小和
  // 对需要更新的dp[j]， 此时dp[j]即[i-1][j]的值，dp[j]即[i][j-1]的值
  // dp[j] = grid[i][j] + min(dp[j-1], dp[j])
  int minPathSum2(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> dp(n, 0);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0) {
          dp[j] = grid[0][0];
        } else if (i == 0) {
          dp[j] = grid[0][j] + dp[j - 1];
        } else if (j == 0) {
          dp[j] = grid[i][0] + dp[j];
        } else {
          dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
        }
      }
    }
    return dp[n - 1];
  }
};