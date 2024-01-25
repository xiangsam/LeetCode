/*
 * @lc app=leetcode.cn id=2859 lang=cpp
 *
 * [2859] 计算 K 置位下标对应元素的和
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int sumIndicesWithKSetBits(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = 0;
    vector<int> oneNums(n, 0);
    if (k == 0) {
      ans += nums[0];
    }
    for (int i = 1; i < n; ++i) {
      oneNums[i] = (i & 1) ? oneNums[i - 1] + 1 : oneNums[i >> 1];
      if (oneNums[i] == k) {
        ans += nums[i];
      }
    }
    return ans;
  }
};
// @lc code=end
