/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> memo;
  vector<int> val;
  int solve(int left, int right) { // 开区间
    int coins = 0;
    if (left >= right - 1)
      return 0;
    if (memo[left][right] != -1) {
      return memo[left][right];
    }
    for (int i = left + 1; i < right; ++i) {
      int sum = val[i] * val[left] * val[right];
      sum += solve(left, i) + solve(i, right);
      memo[left][right] = max(memo[left][right], sum);
    }
    return memo[left][right];
  }
  int maxCoins(vector<int> &nums) {
    int n = nums.size();
    val.resize(n + 2);
    val[0] = val[n + 1] = 1;
    for (int i = 1; i < n + 1; ++i) {
      val[i] = nums[i - 1];
    }
    memo.resize(n + 2, vector<int>(n + 2, -1));
    int ret = solve(0, n + 1);
    return ret;
  }
};
// @lc code=end
