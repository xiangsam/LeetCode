/*
 * @Author: Samrito
 * @Date: 2022-05-16 15:53:13
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-16 16:37:18
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
  // 四个方向的最近搜索
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT_MAX - 1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j] == 0) {
          dp[i][j] = 0;
        } else {
          if (i > 0) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
          }
          if (j > 0) {
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
          }
        }
      }
    }
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (mat[i][j] != 0) {
          if (i < m - 1) {
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
          }
          if (j < n - 1) {
            dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
          }
        }
      }
    }
    return dp;
  }
  // 错误思路， 对连续的1会循环迭代
  int getDistance2(int row, int col, vector<vector<int>> &mat,
                   vector<vector<int>> &distance) {
    cout << "@@@@@" << row << ' ' << col << '\n';
    if (row < 0 || row >= mat.size() || col < 0 || col >= mat[0].size()) {
      return mat.size() * mat[0].size();
    }
    if (distance[row][col] != -1) {
      return distance[row][col];
    }
    if (mat[row][col] == 0) {
      distance[row][col] = 0;
      return 0;
    }
    int tmp1 = getDistance(row - 1, col, mat, distance);
    int tmp2 = getDistance(row + 1, col, mat, distance);
    int tmp3 = getDistance(row, col - 1, mat, distance);
    int tmp4 = getDistance(row, col + 1, mat, distance);
    distance[row][col] = 1 + min({tmp1, tmp2, tmp3, tmp4});
    return distance[row][col];
  }
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> distance(m, vector<int>(n, -1));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        getDistance(i, j, mat, distance);
      }
    }
    return distance;
  }
};

int main() {
  Solution sol = Solution();
  vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  vector<vector<int>> distance = sol.updateMatrix(mat);
  for (auto &line : distance) {
    for (auto &e : line) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}