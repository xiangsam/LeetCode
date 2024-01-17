/*
 * @lc app=leetcode.cn id=1135 lang=cpp
 *
 * [1135] 最低成本连通所有城市
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution1 { // Prim算法
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

class UnionFind {
private:
  vector<int> rank;
  vector<int> father;

public:
  UnionFind(int size) : rank(size, 0), father(size) {
    for (int i = 0; i < size; ++i) {
      father[i] = i;
    }
  }
  int find(int x) {
    if (x != father[x]) {
      father[x] = find(father[x]);
    }
    return father[x];
  }
  bool unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      if (rank[rootX] > rank[rootY]) {
        father[rootY] = rootX;
      } else if (rank[rootX] < rank[rootY]) {
        father[rootX] = rootY;
      } else {
        father[rootY] = rootX;
        rank[rootX] += 1;
      }
      return true;
    }
    return false; // 有环
  }
};
class Solution { // Kruskal Algorithm
public:
  int minimumCost(int n, vector<vector<int>> &connections) {
    UnionFind uf(n + 1);
    auto cmp = [](vector<int> a, vector<int> b) { return a[2] < b[2]; };
    sort(connections.begin(), connections.end(), cmp);
    int totalCost = 0;
    int edgeCount = 0;
    for (const auto &e : connections) {
      if (uf.unionSet(e[0], e[1])) {
        totalCost += e[2];
        ++edgeCount;
      }
    }
    return edgeCount == n - 1 ? totalCost : -1;
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
