/*
 * @lc app=leetcode.cn id=2368 lang=cpp
 *
 * [2368] 受限条件下可到达节点的数目
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution1 {
// DFS
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int, vector<int>> tree;
        for(const auto & edge : edges){
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
        }
        unordered_set<int> restricted_set(restricted.begin(), restricted.end());
        int ans = 0;
        function<void(int, int)> dfs = [&](int x, int father) -> void {
            if(restricted_set.contains(x)){
                return;
            }
            ++ans;
            for(const auto & child : tree[x]){
                if(child != father){
                    dfs(child, x);
                }
            }
        };
        dfs(0, -1);
        return ans;
    }
};

class UnionFind {
private:
    vector<int> f;
    vector<int> rank;
public:
    UnionFind(int n): f(n), rank(n) {
        for(int i = 0; i < n; ++i){
            f[i] = i;
        }
    }
    int find(int x) {
        if (x != f[x])
            x = find(f[x]);
        return f[x];
    }
    void combine(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if (fx != fy){
            if(rank[fx] > rank[fy]){
                f[fy] = fx;
            }else if(rank[fx] < rank[fy]){
                f[fx] = fy;
            }else{
                f[fy] = fx;
                rank[fx]++;
            }
        }
    }
    int count(int x){
        int cnt = 0;
        int fx = find(x);
        for(int i = 0; i < f.size(); ++i){
            if(find(i) == fx)
                ++cnt;
        }
        return cnt;
    }
};
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        UnionFind uf = UnionFind(n);
        unordered_set<int> restricted_set(restricted.begin(), restricted.end());
        for(const auto & edge : edges){
            if(!restricted_set.contains(edge[0]) && !restricted_set.contains(edge[1])){
                uf.combine(edge[0], edge[1]);
            }
        }
        return uf.count(0);
    }
};
// @lc code=end

