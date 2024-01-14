/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isBipartite(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> flag(n, -1);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (flag[i] == -1) {
        q.emplace(i);
        flag[i] = 0;
      }
      while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (const auto &e : graph[node]) {
          if (flag[e] == -1) {
            flag[e] = 1 - flag[node];
            q.emplace(e);
          } else {
            if (flag[e] + flag[node] != 1) {
              return false;
            }
          }
        }
      }
    }
    return true;
  }
};
// @lc code=end
