/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);
    for (const auto &e : prerequisites) {
      graph[e[1]].emplace_back(e[0]);
      ++indegree[e[0]];
    }
    queue<int> q;
    for (int i = 0; i < indegree.size(); ++i) {
      if (!indegree[i]) {
        q.emplace(i);
      }
    }
    vector<int> res;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      res.emplace_back(node);
      for (const auto &e : graph[node]) {
        --indegree[e];
        if (!indegree[e]) {
          q.emplace(e);
        }
      }
    }
    for (const auto &e : indegree) {
      if (e) {
        return vector<int>();
      }
    }
    return res;
  }
};
// @lc code=end
