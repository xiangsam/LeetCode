/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    // 单调递减栈
    int n = nums.size();
    stack<int> stk;
    vector<int> ans(n, -1);
    for (int i = 0; i < 2 * n - 1; ++i) {
      while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
        ans[stk.top()] = nums[i % n];
        stk.pop();
      }
      stk.push(i % n);
    }
    return ans;
  }
};
// @lc code=end
