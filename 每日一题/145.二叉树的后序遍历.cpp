/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    void post_dfs(TreeNode * root, vector<int> & ans){
        if(root == nullptr)
            return;
        post_dfs(root->left, ans);
        post_dfs(root->right, ans);
        ans.emplace_back(root->val);
    }
    vector<int> postorderTraversal1(TreeNode* root) {
        vector<int> ans;
        post_dfs(root, ans);
        return ans;
    }
    vector<int> postorderTraversal(TreeNode * root){
        stack<TreeNode *> stk;
        vector<int> ans;
        TreeNode * ptr = root;
        while(ptr || !stk.empty()){
            while(ptr){
                ans.emplace_back(ptr->val);
                stk.emplace(ptr->left);
                ptr = ptr->right;
            }
            ptr = stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

