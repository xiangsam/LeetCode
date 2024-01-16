/*
 * @lc app=leetcode.cn id=1135 lang=cpp
 *
 * [1135] 最低成本连通所有城市
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
class Solution {
public:
  int minimumCost(int n, vector<vector<int>> &connections) {
    unordered_map<int, vector<pair<int, int>>> graph;
    for (const auto &e : connections) {
      graph[e[0]].emplace_back(e[2], e[1]);
      graph[e[1]].emplace_back(e[2], e[0]);
    }
    unordered_set<int> hash_set;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.emplace(0, 1);
    int totalCost = 0;
    while (hash_set.size() < n && !pq.empty()) {
      auto [cost, city] = pq.top();
      pq.pop();
      if (hash_set.contains(city)) {
        continue;
      }
      hash_set.insert(city);
      totalCost += cost;
      for (const auto &e : graph[city]) {
        if (!hash_set.contains(e.second)) {
          pq.emplace(e);
        }
      }
    }
    return hash_set.size() == n ? totalCost : -1;
  }
};
// @lc code=end
int main() {
  int n = 4; // 城市数
  std::vector<std::vector<int>> connections = {
      {1, 2, 5}, {1, 3, 6}, {2, 3, 1}, {2, 4, 2}, {3, 4, 3}}; // 连接信息

  Solution sol = Solution();
  int cost = sol.minimumCost(n, connections);
  std::cout << "Minimum cost to connect all cities is: " << cost << std::endl;
  return 0;
}
