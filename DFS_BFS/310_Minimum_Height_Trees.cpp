/*
 * @Author: Samrito
 * @Date: 2022-04-12 21:36:03
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-03 23:30:47
 */
#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1)
      return vector<int>{0};
    vector<vector<int>> edge(n, vector<int>{});
    vector<int> degree(n);
    for (const auto &e : edges) {
      edge[e[0]].push_back(e[1]);
      edge[e[1]].push_back(e[0]);
      degree[e[0]]++;
      degree[e[1]]++;
    }
    queue<int> node_degree_1;
    for (int i = 0; i < n; ++i) {
      if (degree[i] == 1) {
        node_degree_1.push(i);
      }
    }
    vector<int> ans;
    while (!node_degree_1.empty()) {
      int n = node_degree_1.size();
      ans.clear();
      while (n--) {
        int node = node_degree_1.front();
        node_degree_1.pop();
        ans.push_back(node);
        for (int i = 0; i < edge[node].size(); ++i) {
          degree[edge[node][i]]--;
          if (degree[edge[node][i]] == 1)
            node_degree_1.push(edge[node][i]);
        }
      }
    }
    return ans;
  }
};