/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class UnionFind {
private:
  vector<int> father;
  vector<int> rank;

public:
  UnionFind(int size) : father(size), rank(size, 0) {
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
  bool allow_union(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      if (rank[rootX] < rank[rootY]) {
        father[rootX] = rootY;
      } else if (rank[rootX] > rank[rootY]) {
        father[rootY] = rootX;
      } else {
        father[rootY] = rootX;
        rank[rootX] += 1;
      }
      return true;
    }
    return false;
  }
};
class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    UnionFind uf(n + 1);
    vector<int> ans;
    for (const auto &e : edges) {
      if (!uf.allow_union(e[0], e[1])) {
        ans = e;
      }
    }
    return ans;
  }
};
// @lc code=end
