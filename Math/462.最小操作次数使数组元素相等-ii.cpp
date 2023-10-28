/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最小操作次数使数组元素相等 II
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int minMoves2(vector<int> &nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    int target = 0;
    if (size % 2 == 0) {
      target = (nums[size / 2 - 1] + nums[size / 2]) / 2;
    } else {
      target = nums[int(size / 2)];
    }
    int res = 0;
    for (const auto &a : nums) {
      res += abs(a - target);
    }
    return res;
  }
};
// @lc code=end
