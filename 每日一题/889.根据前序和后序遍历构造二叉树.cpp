/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 */
#include <iostream>
#include <vector>

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
    unordered_map<int, int> post_value2index;
public:
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int pre_start, int pre_end, int post_start, int post_end){
        if(pre_start > pre_end)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        if(pre_start == pre_end)
            return root;
        int index = post_value2index[preorder[pre_start+1]];
        int left_len = index - post_start + 1;
        root->left = build(preorder, postorder, pre_start+1, pre_start+left_len, post_start, index);
        root->right = build(preorder, postorder, pre_start+left_len+1, pre_end, index+1, post_end-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for(int i = 0; i < n; ++i){
            post_value2index[postorder[i]] = i;
        }
        TreeNode* root = build(preorder, postorder, 0, n-1, 0, n-1);
        return root;
    }
};
// @lc code=end

