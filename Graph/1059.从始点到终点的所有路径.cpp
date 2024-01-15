/*
 * @lc app=leetcode.cn id=1059 lang=cpp
 *
 * [1059] 从始点到终点的所有路径
 */
#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution1 {     // dfs
  vector<int> record; // 记录状态

public:
  bool dfs(vector<vector<int>> &graph, int source, int destination,
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
    vector<vector<int>> graph(n, vector<int>());
    for (const auto &e : edges) {
      graph[e[0]].emplace_back(e[1]);
    }
    if (!graph[destination].empty()) {
      return false;
    }
    vector<bool> visited(n, false);
    record.resize(n, -1);
    return dfs(graph, source, destination, visited);
  }
};
class Solution { // 拓扑排序

public:
  bool leadsToDestination(int n, vector<vector<int>> &edges, int source,
                          int destination) {
    // 反向建图+拓扑排序
    // 反向建图，则只有当所有路径都通时，源节点才会入度为0，被加入队列中
    // 存在环则最后源节点入度不为0
    vector<vector<int>> graph(n, vector<int>());
    vector<int> indegree(n, 0);
    for (const auto &e : edges) {
      graph[e[1]].emplace_back(e[0]);
      ++indegree[e[0]];
    }
    if (indegree[destination]) {
      return false;
    }
    queue<int> q;
    q.emplace(destination);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      if (node == source) {
        return true;
      }
      for (const auto &e : graph[node]) {
        if (--indegree[e] == 0) {
          q.emplace(e);
        }
      }
    }
    return false;
  }
};
// @lc code=end
