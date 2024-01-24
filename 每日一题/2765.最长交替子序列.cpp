/*
 * @lc app=leetcode.cn id=2765 lang=cpp
 *
 * [2765] 最长交替子序列
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int alternatingSubarray(vector<int> &nums) {
    int maxLen = -1;
    int len = 0;
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] - nums[i - 1] == 1) {
        if (len % 2 == 0) {
          ++len;
        } else {
          len = 1;
        }
      } else if (nums[i] - nums[i - 1] == -1) {
        if (len % 2 == 1) {
          ++len;
        } else {
          len = 0;
        }
      } else {
        len = 0;
      }
      maxLen = max(len, maxLen);
    }
    return maxLen == 0 ? -1 : maxLen + 1;
  }
};

// @lc code=end
