/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int missingNumber1(vector<int> &nums) {
    int num = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int target = num * (num + 1) / 2;
    return target - sum;
  }
  int missingNumber(vector<int> &nums) {
    int n = nums.size();
    int ans = n;
    for (int i = 0; i < n; ++i) {
      ans ^= (i ^ nums[i]);
    }
    return ans;
  }
};
// @lc code=end
