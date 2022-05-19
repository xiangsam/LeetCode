/*
 * @Author: Samrito
 * @Date: 2022-05-19 15:41:55
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-19 16:03:38
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int numSize = nums.size();
    vector<int> dp(numSize, 1);
    int ans = 1;
    for (int i = 1; i < numSize; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
  int lengthOfLIS2(vector<int> &nums) {
    // O(nlogn)
    int numSize = nums.size();
    vector<int> dp(numSize, 1);
    dp.push_back(nums[0]);
    for (int i = 1; i < numSize; ++i) {
      if (dp.back() < nums[i]) {
        dp.push_back(nums[i]);
      } else {
        auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
        *itr = nums[i];
      }
    }
    return dp.size();
  }
};