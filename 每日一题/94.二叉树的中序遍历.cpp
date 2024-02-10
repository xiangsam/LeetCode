/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */
#include <iostream>
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
    void in_dfs(TreeNode * root, vector<int> & res){
        if(root == nullptr)
            return;
        in_dfs(root->left, res);
        res.emplace_back(root->val);
        in_dfs(root->right, res);
    }
    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> res;
        in_dfs(root, res);
        return res;
    }
    vector<int> inorderTraversal(TreeNode * root){
        stack<TreeNode *> stk;
        TreeNode * ptr = root;
        vector<int> res;
        while(ptr || !stk.empty()){
            while(ptr){
                stk.emplace(ptr);
                ptr = ptr->left;
            }
            ptr = stk.top();
            stk.pop();
            res.emplace_back(ptr->val);
            ptr = ptr->right;
        }
        return res;
    }
};
// @lc code=end

