/*
 * @lc app=leetcode.cn id=2865 lang=cpp
 *
 * [2865] 美丽塔 I
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
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
// @lc code=end
