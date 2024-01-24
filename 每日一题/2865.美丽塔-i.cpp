/*
 * @lc app=leetcode.cn id=2865 lang=cpp
 *
 * [2865] 美丽塔 I
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution1 {
public:
  long long getSum(vector<int> &maxHeights, int peak) {
    long long res = maxHeights[peak];
    int upper = maxHeights[peak];
    for (int i = peak - 1; i >= 0; --i) {
      if (maxHeights[i] >= upper) {
        res += upper;
      } else {
        res += maxHeights[i];
        upper = maxHeights[i];
      }
    }
    upper = maxHeights[peak];
    for (int i = peak + 1; i < maxHeights.size(); ++i) {
      if (maxHeights[i] >= upper) {
        res += upper;
      } else {
        res += maxHeights[i];
        upper = maxHeights[i];
      }
    }
    return res;
  }
  long long maximumSumOfHeights(vector<int> &maxHeights) {
    vector<int> localMaxPoints;
    int n = maxHeights.size();
    if (n == 1) {
      return maxHeights[0];
    }
    for (int i = 0; i < n; ++i) {
      if (i == 0 && i + 1 < n) {
        if (maxHeights[i] >= maxHeights[i + 1])
          localMaxPoints.emplace_back(i);
      } else if (i == n - 1 && i - 1 >= 0) {
        if (maxHeights[i] >= maxHeights[i - 1])
          localMaxPoints.emplace_back(i);
      } else {
        if (maxHeights[i] >= maxHeights[i - 1] &&
            maxHeights[i] >= maxHeights[i + 1]) {
          localMaxPoints.emplace_back(i);
        }
      }
    }
    long long ans = 0;
    for (const auto &e : localMaxPoints) {
      ans = max(ans, getSum(maxHeights, e));
    }
    return ans;
  }
};
class Solution { // 单调栈做法
public:
  long long maximumSumOfHeights(vector<int> &maxHeights) {
    // 对峰顶而言，左边是单调非减，右边是单调非增
    //  对每个位置i，以之为峰顶，计算prefixSum，和suffixSum
    int n = maxHeights.size();
    vector<long long> prefixSum(n, 0), suffixSum(n, 0);
    stack<int> prefixStack, suffixStack;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      while (!prefixStack.empty() &&
             maxHeights[i] < maxHeights[prefixStack.top()]) {
        prefixStack.pop();
      }
      if (prefixStack.empty()) {
        prefixSum[i] = (long long)(i + 1) * maxHeights[i];
      } else {
        prefixSum[i] = prefixSum[prefixStack.top()] +
                       (long long)(i - prefixStack.top()) * maxHeights[i];
      }
      prefixStack.emplace(i);
    }
    for (int i = n - 1; i >= 0; --i) {
      while (!suffixStack.empty() &&
             maxHeights[i] < maxHeights[suffixStack.top()]) {
        suffixStack.pop();
      }
      if (suffixStack.empty()) {
        suffixSum[i] = (long long)(n - i) * maxHeights[i];
      } else {
        suffixSum[i] = suffixSum[suffixStack.top()] +
                       (long long)(suffixStack.top() - i) * maxHeights[i];
      }
      ans = max(ans, suffixSum[i] + prefixSum[i] - maxHeights[i]);
      suffixStack.emplace(i);
    }
    return ans;
  }
};
// @lc code=end
