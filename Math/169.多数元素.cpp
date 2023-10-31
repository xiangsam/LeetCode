/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int majorityElement1(vector<int> &nums) {
    //排序中间的数肯定是 时间复杂度O(nlogn)
    sort(nums.begin(), nums.end());
    int mid = nums.size() / 2;
    return nums[mid];
  }
  int majorityElement(vector<int> &nums) {
    // 多数投票算法 时间复杂度O(n)，空间复杂度O(1)
    // 如果数组中没有多数元素，则返回值可能是无效的随机元素
    int cnt = 0, memo = 0;
    for (const auto &e : nums) {
      if (cnt == 0) {
        memo = e;
        ++cnt;
      } else {
        if (memo == e) {
          ++cnt;
        } else {
          --cnt;
        }
      }
    }
    return memo;
  }
};
// @lc code=end
