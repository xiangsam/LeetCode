/*
 * @lc app=leetcode.cn id=1059 lang=cpp
 *
 * [1059] 从始点到终点的所有路径
 */
#include <cstddef>
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
  vector<int> record; // 记录状态

public:
  bool dfs(unordered_map<int, set<int>> &graph, int source, int destination,
           vector<bool> &visited) {
    if (graph[source].empty()) {
      return source == destination;
    }
    if (record[source] != -1) {
      return record[source];
    }
    if (visited[source]) {
      return false;
    }
    visited[source] = true;
    bool res = true;
    for (const auto &e : graph[source]) {
      res &= dfs(graph, e, destination, visited);
    }
    visited[source] = false;
    record[source] = res;
    return res;
  }
  bool leadsToDestination(int n, vector<vector<int>> &edges, int source,
                          int destination) {
    unordered_map<int, set<int>> graph;
    for (const auto &e : edges) {
      graph[e[0]].insert(e[1]);
    }
    if (!graph[destination].empty()) {
      return false;
    }
    vector<bool> visited(n, false);
    record.resize(n, -1);
    return dfs(graph, source, destination, visited);
  }
};
// @lc code=end
