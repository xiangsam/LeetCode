/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    // 对角线翻转
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    // 垂直中轴线翻转
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n / 2; ++j) {
        swap(matrix[i][j], matrix[i][n - j - 1]);
      }
    }
  }
};
// @lc code=end
