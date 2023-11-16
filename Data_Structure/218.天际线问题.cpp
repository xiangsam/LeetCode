/*
 * @lc app=leetcode.cn id=218 lang=cpp
 *
 * [218] 天际线问题
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    priority_queue<pair<int, int>> max_heap;
    vector<vector<int>> ans;
    int cur_x, cur_h, i = 0, n = buildings.size();
    while (!max_heap.empty() || i < n) {
      if (max_heap.empty() ||
          i < n && buildings[i][0] <= max_heap.top().second) {
        cur_x = buildings[i][0];
        while (i < n && cur_x == buildings[i][0]) {
          max_heap.emplace(buildings[i][2], buildings[i][1]);
          ++i;
        }
      } else {
        cur_x = max_heap.top().second;
        while (!max_heap.empty() && cur_x >= max_heap.top().second) {
          max_heap.pop();
          // 最终为空则不可显（落到地平线），
          // 否则落到可显建筑上（右坐标比cur更大且最高的楼）
        }
      }
      cur_h = max_heap.empty() ? 0 : max_heap.top().first;
      if (ans.empty() || cur_h != ans.back()[1]) {
        ans.push_back({cur_x, cur_h});
      }
    }
    return ans;
  }
};
// @lc code=end
