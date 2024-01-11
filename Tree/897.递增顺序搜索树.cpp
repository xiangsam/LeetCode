/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
 */
#include <iostream>
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
public:
  void convert(TreeNode *root, TreeNode *&list_Tree) {
    if (root == nullptr) {
      return;
    }
    convert(root->left, list_Tree);
    list_Tree->right = root;
    list_Tree = list_Tree->right;
    root->left = nullptr;
    convert(root->right, list_Tree);
  }
  TreeNode *increasingBST(TreeNode *root) {
    TreeNode *dummy = new TreeNode();
    TreeNode *ptr = dummy;
    convert(root, ptr);
    return dummy->right;
  }
};
// @lc code=end
