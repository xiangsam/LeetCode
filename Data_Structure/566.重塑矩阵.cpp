/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> matrixReshape0(vector<vector<int>> &mat, int r, int c) {
    int m = mat.size(), n = mat[0].size();
    if (m * n != r * c) {
      return mat;
    }
    vector<vector<int>> ans(r, vector<int>(c, 0));
    int idx_r = 0, idx_c = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[idx_r][idx_c] = mat[i][j];
        ++idx_c;
        if (idx_c >= c) {
          idx_r += 1;
          idx_c %= c;
        }
      }
    }
    return ans;
  }
  vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
    int m = mat.size(), n = mat[0].size();
    if (m * n != r * c) {
      return mat;
    }
    vector<vector<int>> ans(r, vector<int>(c, 0));
    for (int i = 0; i < m * n; ++i) {
      ans[i / c][i % c] = mat[i / n][i % n];
    }
    return ans;
  }
};
// @lc code=end
