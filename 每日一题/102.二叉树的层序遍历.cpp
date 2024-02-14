/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode *> nodeQueue;
        nodeQueue.emplace(root);
        while(!nodeQueue.empty()){
            int n = nodeQueue.size();
            vector<int> tmp;
            for(int i = 0; i < n; ++i){
                TreeNode * ptr = nodeQueue.front();
                nodeQueue.pop();
                tmp.emplace_back(ptr->val);
                if(ptr->left){
                    nodeQueue.emplace(ptr->left);
                }if(ptr->right){
                    nodeQueue.emplace(ptr->right);
                }
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
// @lc code=end

