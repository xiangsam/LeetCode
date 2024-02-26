/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] 二叉搜索树的范围和
 */
#include <iostream>
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
    void in_dfs(TreeNode* root, int low, int high, int& ans){
        if(root == nullptr)
            return;

        in_dfs(root->left, low, high, ans);
        if(root->val >= low && root->val <= high){
            ans += root->val;
        }
        if(root->val > high)
            return;
        in_dfs(root->right, low, high, ans);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        in_dfs(root, low, high, ans);
        return ans;
    }
};
// @lc code=end

