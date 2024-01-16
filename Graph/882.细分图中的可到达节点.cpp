/*
 * @lc app=leetcode.cn id=882 lang=cpp
 *
 * [882] 细分图中的可到达节点
 */
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution1 { // TLE
  unordered_map<int, int> record;

public:
  void dfs(unordered_map<int, vector<int>> &graph, int node, int maxMoves,
           int &step, unordered_set<int> &ans) {
    if (step > maxMoves) {
      return;
    }
    if (ans.contains(node) && step >= record[node]) {
      // 已走步数更多，不可能走出新的节点
      return;
    }
    ans.insert(node);
    record[node] = step;
    if (graph[node].empty()) {
      return;
    }
    for (const auto &e : graph[node]) {
      step += 1;
      dfs(graph, e, maxMoves, step, ans);
      step -= 1;
    }
    return;
  }
  int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
    unordered_map<int, vector<int>> graph;
    int id = n;
    for (const auto &e : edges) {
      int front = e[0];
      for (int i = 0; i < e[2]; ++i) {
        graph[front].emplace_back(id);
        graph[id].emplace_back(front);
        front = id;
        ++id;
      }
      graph[front].emplace_back(e[1]);
      graph[e[1]].emplace_back(front);
    }
    unordered_set<int> ans;
    int step = 0;
    dfs(graph, 0, maxMoves, step, ans);
    return ans.size();
  }
};

class Solution {
public:
  int encode(int u, int v, int n) { return u * n + v; }
  int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
    unordered_map<int, vector<pair<int, int>>> adList; // u: [v, dist]
    for (const auto &edge : edges) {
      adList[edge[0]].emplace_back(edge[1], edge[2]);
      adList[edge[1]].emplace_back(edge[0], edge[2]);
    }
    int reachableNodes = 0;
    unordered_set<int> visited;
    unordered_map<int, int> used;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.emplace(0, 0); // [dist, v]
    while (!pq.empty() && pq.top().first <= maxMoves) {
      auto [nds, node] = pq.top();
      pq.pop();
      if (visited.contains(node)) {
        continue;
      }
      visited.emplace(node);
      ++reachableNodes;
      for (const auto &[v, v_nds] : adList[node]) {
        if (nds + v_nds + 1 <= maxMoves && !visited.contains(v)) {
          pq.emplace(nds + v_nds + 1, v);
        }
        used[encode(node, v, n)] = min(v_nds, maxMoves - nds);
      }
    }
    for (const auto &edge : edges) {
      int u = edge[0], v = edge[1], nds = edge[2];
      reachableNodes += min(nds, used[encode(u, v, n)] + used[encode(v, u, n)]);
    }
    return reachableNodes;
  }
};
// @lc code=end
