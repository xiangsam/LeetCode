/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class NumMatrix {
  vector<vector<int>> psum;

public:
  NumMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    psum.resize(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        psum[i][j] = matrix[i - 1][j - 1] + psum[i - 1][j] + psum[i][j - 1] -
                     psum[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return psum[row2 + 1][col2 + 1] - psum[row1][col2 + 1] -
           psum[row2 + 1][col1] + psum[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
