/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findTargetSumWays1(vector<int> &nums, int target) {
    int max_sum = accumulate(nums.begin(), nums.end(), 0);
    if (target > max_sum || target < -max_sum) {
      return 0;
    }
    int n = nums.size();
    vector<vector<int>> dp(
        n, vector<int>(2 * max_sum + 1, 0)); // 0, ..., ms, -1, ..., -ms
    if (nums[0] == 0)
      dp[0][nums[0]] = 2;
    else {
      dp[0][nums[0]] = 1;
      dp[0][max_sum + nums[0]] = 1;
    }
    for (int i = 1; i < n; ++i) {
      for (int k = 0; k <= 2 * max_sum; ++k) {
        if (nums[i] == 0) {
          dp[i][k] = 2 * dp[i - 1][k];
          continue;
        }
        if (k <= max_sum) { // k 为非负数
          if (k - nums[i] < 0) {
            dp[i][k] = dp[i - 1][max_sum - (k - nums[i])];
          } else {
            dp[i][k] = dp[i - 1][k - nums[i]];
          }
          if (k + nums[i] <= max_sum) {
            dp[i][k] += dp[i - 1][k + nums[i]];
          }
        } else {
          int tk = max_sum - k; // tk < 0
          if (tk + nums[i] >= 0) {
            dp[i][k] = dp[i - 1][tk + nums[i]];
          } else {
            dp[i][k] = dp[i - 1][max_sum - (tk + nums[i])];
          }
          if (max_sum - (tk - nums[i]) <= 2 * max_sum) {
            dp[i][k] += dp[i - 1][max_sum - (tk - nums[i])];
          }
        }
      }
    }
    if (target >= 0)
      return dp[n - 1][target];
    else
      return dp[n - 1][max_sum - target];
  }
  int findTargetSumWays(vector<int> &nums, int target) { //简化if语句
    int max_sum = accumulate(nums.begin(), nums.end(), 0);
    if (target > max_sum || target < -max_sum) {
      return 0;
    }
    int n = nums.size();
    vector<vector<int>> dp(
        n, vector<int>(2 * max_sum + 1, 0)); // 0, ..., ms, -1, ..., -ms
    if (nums[0] == 0)
      dp[0][max_sum] = 2;
    else {
      dp[0][max_sum + nums[0]] = 1;
      dp[0][max_sum - nums[0]] = 1;
    }
    for (int i = 1; i < n; ++i) {
      for (int k = 0; k <= 2 * max_sum; ++k) {
        // 全为0时，：后面的0显然正确
        // 非全为0时，只有当i==n-1时,
        // dp[i][0]才为1，因此考虑上一层时dp[i-1][0]永远为0
        int l = (k - nums[i] >= 0) ? k - nums[i] : 0;
        int r = (k + nums[i] <= 2 * max_sum) ? k + nums[i] : 0;
        dp[i][k] = dp[i - 1][l] + dp[i - 1][r];
      }
    }
    return dp[n - 1][max_sum + target];
  }
};
// @lc code=end
