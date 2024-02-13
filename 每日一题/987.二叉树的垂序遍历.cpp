/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <multiset>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void pre_dfs(TreeNode * root, map<int, multiset<pair<int, int>>> & ans, pair<int, int> pos){
        if(root == nullptr){
            return;
        }
        ans[pos.second].insert({pos.first, root->val});
        pre_dfs(root->left, ans, {pos.first+1, pos.second - 1});
        pre_dfs(root->right, ans, {pos.first+1, pos.second  +1});
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, multiset<pair<int, int>>> ans;
        pre_dfs(root, ans, {0, 0});
        vector<vector<int>> res;
        for(const auto & [key, value] : ans){
            vector<int> tmp;
            for(const auto & e : value){
                tmp.emplace_back(e.second);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};
// @lc code=end

