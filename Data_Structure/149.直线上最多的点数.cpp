/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxPoints(vector<vector<int>> &points) {
    // 斜率(Y2-Y1)/(X2-X1)
    int n = points.size();
    int ans = 1;
    unordered_map<double, int> hashMap;
    unordered_map<double, int> hashMap2;
    for (int i = 0; i < n - 1; ++i) {
      // 总是以一个点为起点，因此不需要考虑截距
      for (int j = i + 1; j < n; ++j) {
        if (points[i][0] == points[j][0]) { // 斜率不存在
          ++hashMap2[points[i][0]];
        } else {
          double dk = double(points[i][1] - points[j][1]) /
                      (points[i][0] - points[j][0]);
          if (dk == -0.0) {
            dk = 0.0;
          }
          double c = points[i][1] - points[i][0] * dk; // 截距
          ++hashMap[dk];
        }
      }
      for (const auto &e : hashMap) {
        ans = max(ans, e.second + 1);
      }
      for (const auto &e : hashMap2) {
        ans = max(ans, e.second + 1);
      }
      hashMap.clear();
      hashMap2.clear();
    }
    return ans;
  }
};
// @lc code=end
