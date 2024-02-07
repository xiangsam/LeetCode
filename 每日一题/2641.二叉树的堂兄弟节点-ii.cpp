/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 *
 * [2641] 二叉树的堂兄弟节点 II
 */
#include <iostream>
#include <vector>
#include <queue>
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
    void bfs(TreeNode * root){
        queue<TreeNode *> q;
        q.emplace(root);
        while(!q.empty()){
            int width = q.size();
            vector<TreeNode *> tmp;
            vector<int> childSum(width, 0);
            int sum = 0;
            for(int i = 0; i < width; ++i){
                TreeNode * node = q.front();
                q.pop();
                tmp.emplace_back(node);
                if(node->left){
                    childSum[i] += node->left->val;
                    q.emplace(node->left);
                }if(node->right){
                    childSum[i] += node->right->val;
                    q.emplace(node->right);
                }
                sum += childSum[i];
            }
            for(int i = 0; i < width; ++i){
                tmp[i]->val = sum - childSum[i];
            }
        }
    }
    void dfs(TreeNode * root, int parent_val){
        if(root == nullptr){
            return;
        }
        dfs(root->left, root->val);
        dfs(root->right, root->val);
        root->val = parent_val;
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        bfs(root);
        dfs(root, 0);
        return root;
    }
};
// @lc code=end

