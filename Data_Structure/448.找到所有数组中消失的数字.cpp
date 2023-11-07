/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> findDisappearedNumbers1(vector<int> &nums) {
    int n = nums.size();
    vector<int> flag(n + 1, 0);
    for (const auto &e : nums) {
      ++flag[e];
    }
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
      if (!flag[i]) {
        res.push_back(i);
      }
    }
    return res;
  }
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = nums.size();
    vector<int> res;
    for (const int &e : nums) {
      int pos = abs(e) - 1;
      if (nums[pos] > 0) {
        nums[pos] = -nums[pos];
      }
    }
    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0) {
        res.push_back(i + 1);
      }
    }
    return res;
  }
};
// @lc code=end
