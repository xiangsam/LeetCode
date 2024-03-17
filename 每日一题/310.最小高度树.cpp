/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees1(int n, vector<vector<int>>& edges) {
        // 直接dfs， TLE
        unordered_map<int, vector<int>> tree;
        for(const auto & edge : edges){
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
        }
        int max_depth = -1;
        function<void(int, int, int)> dfs = [&](int x, int father, int depth) -> void {
            max_depth = max(depth, max_depth);
            for(const auto & node : tree[x]){
                if(father != node){
                    dfs(node, x, depth+1);
                }
            }
        };
        vector<pair<int, int>> ans;
        for(int i = 0; i < n; ++i){
            max_depth = -1;
            dfs(i, -1, 0);
            ans.emplace_back(max_depth, i);
        }
        sort(ans.begin(), ans.end());
        int min_depth = ans[0].first;
        vector<int> res;
        res.emplace_back(ans[0].second);
        for(auto itr = ans.begin()+1; itr != ans.end(); ++itr){
            if(itr->first != min_depth)
                break;
            res.emplace_back(itr->second);
        }return res;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return {0};
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> tree;
        for(const auto & edge : edges){
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
            ++degree[edge[0]];
            ++degree[edge[1]];
        }
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(degree[i] == 1){
                q.emplace(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.clear();
            int q_size = q.size();
            for(int i = 0; i < q_size; ++i){
                int node = q.front();
                q.pop();
                ans.emplace_back(node);
                for(const auto & neibor : tree[node]){
                    --degree[neibor];
                    if(degree[neibor] == 1){
                        q.emplace(neibor);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

