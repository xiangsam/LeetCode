/*
 * @Author: Samrito
 * @Date: 2022-05-05 11:01:25
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-14 22:32:21
 */
#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
  int numberOfArithmeticSlices(vector<int> &nums) {
    int length = nums.size();
    if (length < 3) {
      return 0;
    }
    int ans = 0;
    vector<vector<bool>> isPassed(length, vector<bool>(length, false));
    for (int i = 0; i < length; ++i) {
      isPassed[i][i] = true;
      isPassed[i][i + 1] = true;
    }
    for (int i = 0; i < length; ++i) {
      for (int j = i + 2; j < length; ++j) {
        if (isPassed[i][j - 1] &&
            ((nums[j] - nums[j - 1]) == nums[j - 1] - nums[j - 2])) {
          isPassed[i][j] = true;
          ans++;
        }
      }
    }
    return ans;
  }
  int numberOfArithmeticSlices2(vector<int> &nums) {
    int length = nums.size();
    vector<int> dp(length, 0);
    if (length < 3) {
      return 0;
    }
    for (int i = 2; i < length; ++i) {
      if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1]) {
        dp[i] = dp[i - 1] + 1; // +1 表示num[i-2]到num[i]这个等差数组
      }
    }
    return accumulate(dp.begin(), dp.end(), 0);
  }
};