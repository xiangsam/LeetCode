/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> dq;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (!dq.empty() && dq.front() == i - k) {
        dq.pop_front(); // 不在划动窗口中，直接去掉
      }
      while (!dq.empty() && nums[dq.back()] < nums[i]) {
        dq.pop_back(); // 维持从左到右单调递减
      }
      dq.push_back(i);
      if (i >= k - 1) {
        ans.push_back(nums[dq.front()]);
      }
    }
    return ans;
  }
};
// @lc code=end
