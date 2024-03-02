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
class Solution {
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
// @lc code=end

