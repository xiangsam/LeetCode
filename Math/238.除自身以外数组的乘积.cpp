/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int>
  productExceptSelf(vector<int> &nums) { // 时间复杂度O(n), 空间复杂度O(n)
    int size = nums.size();
    vector<int> prefix(size, 0), suffix(size, 0);
    prefix[0] = nums[0];
    suffix[size - 1] = nums[size - 1];
    for (int i = 1; i < size; ++i) {
      prefix[i] = prefix[i - 1] * nums[i];
    }
    for (int i = size - 2; i >= 0; --i) {
      suffix[i] = suffix[i + 1] * nums[i];
    }
    vector<int> ans(size, 0);
    ans[0] = suffix[1];
    ans[size - 1] = prefix[size - 2];
    for (int i = 1; i < size - 1; ++i) {
      ans[i] = prefix[i - 1] * suffix[i + 1];
    }
    return ans;
  }
  vector<int>
  productExceptSelf1(vector<int> &nums) { // 时间复杂度O(n), 空间复杂度O(1)
    int size = nums.size();
    vector<int> ans(size, 0);
    int prefix = 1, suffix = 1;
    ans[size - 1] = nums[size - 1];
    for (int i = size - 2; i >= 0; --i) {
      ans[i] = nums[i] * ans[i + 1];
    }
    for (int i = 0; i < size - 1; ++i) {
      ans[i] = prefix * ans[i + 1];
      prefix *= nums[i];
    }
    ans[size - 1] = prefix;
    return ans;
  }
};
// @lc code=end
