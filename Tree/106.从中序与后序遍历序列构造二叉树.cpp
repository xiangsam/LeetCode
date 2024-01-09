/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  unordered_map<int, int> in_value2index;

public:
  TreeNode *build(vector<int> &inorder, vector<int> &postorder, int in_start,
                  int in_end, int post_start, int post_end) {
    if (post_start > post_end) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(postorder[post_end]);
    if (post_start == post_end) {
      return root;
    }
    int index = in_value2index[postorder[post_end]];
    root->left = build(inorder, postorder, in_start, index - 1, post_start,
                       post_end - in_end + index - 1);
    root->right = build(inorder, postorder, index + 1, in_end,
                        post_end - in_end + index, post_end - 1);
    return root;
  }
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      in_value2index[inorder[i]] = i;
    }
    TreeNode *root = build(inorder, postorder, 0, inorder.size() - 1, 0,
                           postorder.size() - 1);
    return root;
  }
};
// @lc code=end
