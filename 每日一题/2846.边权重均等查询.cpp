/*
 * @lc app=leetcode.cn id=2846 lang=cpp
 *
 * [2846] 边权重均等查询
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    const int W = 26;
    int find(vector<int> & uf, int i){
        if(uf[i] != i)
            uf[i] = find(uf, uf[i]);
        return uf[i];
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<unordered_map<int, int>> neighbors(n);
        for(const auto & edge : edges){
            neighbors[edge[0]][edge[1]] = edge[2];
            neighbors[edge[1]][edge[0]] = edge[2];
        }
        int m = queries.size();
        vector<vector<pair<int, int>>> queryVec(n);
        for(int i = 0; i < m; ++i){
            queryVec[queries[i][0]].push_back({queries[i][1], i});
            queryVec[queries[i][1]].push_back({queries[i][0], i});
        }
        vector<vector<int>> count(n, vector<int>(W+1));
        vector<int> visited(n), uf(n), lca(m);
        function<void(int, int)> tarjan = [&](int node, int parent){
            if(parent != -1){
                count[node] = count[parent];
                count[node][neighbors[node][parent]]++; //使用unorderd_map不担心不存在
            }
            uf[node] = node;
            for(auto [child, _] : neighbors[node]){
                if(child == parent)
                    continue;
                tarjan(child, node);
                uf[child] = node;
            }
            for(auto [node1, index] : queryVec[node]){
                if(node != node1 && !visited[node1]){
                    continue;
                }
                lca[index] = find(uf, node1);
            }
            visited[node] = 1;
        };
        tarjan(0, -1);
        vector<int> res(m);
        for(int i = 0; i < m; ++i){
            int totalCount = 0, maxCount = 0;
            for(int j = 1; j <= W; ++j){
                int t = count[queries[i][0]][j] + count[queries[i][1]][j] - 2 * count[lca[i]][j];
                maxCount = max(maxCount, t);
                totalCount += t;
            }
            res[i] = totalCount - maxCount;
        }
        return res;
    }
};
// @lc code=end

