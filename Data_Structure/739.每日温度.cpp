/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> dailyTemperatures1(vector<int> &temperatures) {
    // 可以看出新来元素和左边元素从右到左比较（可以比较多次），用栈解决
    int n = temperatures.size();
    stack<int> stk;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; ++i) {
      while (!stk.empty() && temperatures[stk.top()] < temperatures[i]) {
        ans[stk.top()] = i - stk.top();
        stk.pop();
      }
      stk.emplace(i);
    }
    return ans;
  }
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> next(101, INT_MAX);
    vector<int> ans(n, 0);
    for (int i = n - 1; i >= 0; --i) {
      int upWarmIndex = INT_MAX;
      for (int t = temperatures[i] + 1; t <= 100; ++t) {
        upWarmIndex = min(upWarmIndex, next[t]);
      }
      if (upWarmIndex != INT_MAX) {
        ans[i] = upWarmIndex - i;
      }
      next[temperatures[i]] = i;
    }
    return ans;
  }
};
// @lc code=end
