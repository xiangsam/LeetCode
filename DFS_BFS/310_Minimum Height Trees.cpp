/*
 * @Author: Samrito
 * @Date: 2022-04-12 21:36:03
 * @LastEditors: Samrito
 * @LastEditTime: 2022-04-12 21:42:19
 */
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    vector<vector<bool>> edge(n, vector<bool>(n, false));
    for (const auto &e : edges) {
      edge[e[0]][e[1]] = true;
      edge[e[1]][e[0]] = true;
    }
    vector<pair<int, int>> height = {};
  }
  
};