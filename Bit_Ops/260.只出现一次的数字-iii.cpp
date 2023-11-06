/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    int n = nums.size();
    if (n == 2) {
      return nums;
    }
    int xor_all = 0;
    for (const auto &e : nums) {
      xor_all ^= e;
    }
    int lowest = long(xor_all) & (-long(xor_all)); //必然不是0
    int class1 = 0, class2 = 0;
    for (const auto &e : nums) {
      if (lowest & e) {
        class1 ^= e;
      } else {
        class2 ^= e;
      }
    }
    return vector<int>{class1, class2};
  }
};
// @lc code=end
