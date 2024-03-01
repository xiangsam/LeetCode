/*
 * @lc app=leetcode.cn id=2581 lang=cpp
 *
 * [2581] 统计可能的树根数目
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    void dfs(unordered_map<int, vector<int>> tree, unordered_map<int, unordered_set<int>> guesses, int root, int &cnt, int K, unordered_set<int> visited){
        visited.insert(root); // 记录dfs状态，避免无限循环
        if(cnt >= K)
            return;
        for(const auto & child : tree[root]){
            if(!visited.contains(child)){
                if(guesses[root].contains(child))
                    cnt += 1;
                dfs(tree, guesses, child, cnt, K, visited);
            }
        }
    }
    int rootCount1(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        // 朴素方法，TLE
        unordered_map<int, vector<int>> tree;
        for(const auto &edge : edges){
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
        }
        unordered_map<int, unordered_set<int>> guesses_map;
        for(const auto &guess : guesses)
            guesses_map[guess[0]].insert(guess[1]);
        int n = tree.size(); // edges由树而来，不会出现孤立点
        // tree不会出现环，无须判断
        int ans = 0;
        for(int root = 0; root < n; ++root){
            int cnt = 0;
            unordered_set<int> visited;
            dfs(tree, guesses_map, root, cnt, k, visited);
            if(cnt >= k)
                ++ans;
        }
        return ans;
    }
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k){
        unordered_map<int, vector<int>> tree;
        for(const auto &edge : edges){
            tree[edge[0]].emplace_back(edge[1]);
            tree[edge[1]].emplace_back(edge[0]);
        }
        auto h = [](int x, int y) -> long long {
            return (long long) x << 20 | y;
        };
        unordered_set<long long> guesses_set;
        for(const auto & guess : guesses){
            guesses_set.insert(h(guess[0], guess[1]));
        }
        int cnt = 0, ans = 0;
        function<void(int, int)> dfs = [&](int x, int father) -> void {
            for(const auto & child : tree[x]){
                if(child != father){
                    if(guesses_set.contains(h(x, child)))
                        ++cnt;
                    dfs(child, x);
                }
            }
        };
        dfs(0, -1); // 以0为根节点dfs;
        function<void(int, int, int)> redfs = [&](int x, int father, int cnt) -> void {
            if(cnt >= k){
                ++ans;
            }
            for(const auto & child : tree[x]){
                if(child != father){
                    redfs(child, x, cnt + guesses_set.count(h(child, x)) - guesses_set.count(h(x, child)));
                }
            }
        };
        redfs(0, -1, cnt);
        return ans;
    }
};
// @lc code=end

