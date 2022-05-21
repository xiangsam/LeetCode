/*
 * @Author: Samrito
 * @Date: 2022-05-21 10:48:11
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-21 11:07:58
 */
#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int length = nums.size();
    if (length <= 1) {
      return false; // nums[i] >= 1
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }
    int target = sum / 2;
    vector<vector<bool>> dp(length, vector<bool>(target + 1, false));
    for (int i = 0; i < length; ++i) {
      for (int j = 0; j <= target; ++j) {
        if (j == 0) {
          dp[i][0] = true;
        } else if (i == 0) {
          dp[0][j] = (nums[0] == j);
        } else {
          dp[i][j] = dp[i - 1][j];
          if (nums[i] <= j) {
            dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i]];
          }
        }
      }
    }
    for (int i = 0; i < length; ++i) {
      if (dp[i][target] == true) {
        return true;
      }
    }
    return false;
  }
  //使用空间压缩
  bool canPartition2(vector<int> &nums) {
    int length = nums.size();
    if (length <= 1) {
      return false; // nums[i] >= 1
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) {
      return false;
    }
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    for (int idx = 0; idx < length; ++idx) {
      for (int w = target; w >= nums[idx];
           --w) { //只有w > nums[idx]才可能为true
        if (idx == 0) {
          dp[w] = (nums[idx] == w);
        } else {
          dp[w] = dp[w] || dp[w - nums[idx]];
        }
        if (w == target && dp[w]) {
          return true;
        }
      }
    }
    return false;
  }
};