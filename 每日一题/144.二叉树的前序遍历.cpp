/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
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
    void dfs(TreeNode * root, vector<int> & ans){
        if(root == nullptr)
            return;
        ans.emplace_back(root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
    vector<int> preorderTraversal(TreeNode * root){
        stack<TreeNode *> stk;
        vector<int> ans;
        TreeNode * ptr = root;
        while(ptr || !stk.empty()){
            while(ptr){
                ans.emplace_back(ptr->val);
                stk.emplace(ptr->right);
                ptr = ptr->left;
            }
            ptr = stk.top();
            stk.pop();
        }
        return ans;
    }
};
// @lc code=end

