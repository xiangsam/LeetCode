/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 */
#include <iostream>
#include <vector>
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
    TreeNode *parantX, *parantY;
    int depthX, depthY;
public:
    void dfs(TreeNode * root, int depth, int x, int y){
        if(root == nullptr){
            return;
        }
        if((root->left && root->left->val == x) || (root->right  && root->right->val == x)){
            depthX = depth+1;
            parantX = root;
        }
        if((root->left && root->left->val == y) || (root->right  && root->right->val == y)){
            depthY = depth+1;
            parantY = root;
        }
        dfs(root->left, depth+1, x, y);
        dfs(root->right, depth + 1, x , y);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0, x, y);
        if(depthX == depthY && parantX != parantY)
            return true;
        return false;
    }
};
// @lc code=end

