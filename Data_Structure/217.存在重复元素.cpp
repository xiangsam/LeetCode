/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> hash;
    for (const auto &e : nums) {
      ++hash[e];
      if (hash[e] > 1) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
