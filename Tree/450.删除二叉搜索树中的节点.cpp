/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
  TreeNode *getMin(TreeNode *root) {
    if (root == nullptr || root->left == nullptr) {
      return root;
    }
    return getMin(root->left);
  }
  TreeNode *deleteNode(TreeNode *root, int key) {
    TreeNode *tmp;
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else {
      if (root->left != nullptr && root->right != nullptr) {
        tmp = getMin(root->right);
        root->val = tmp->val;
        root->right = deleteNode(root->right, tmp->val);
      } else {
        tmp = root;
        if (root->left == nullptr) {
          root = root->right;
        } else if (root->right == nullptr) {
          root = root->left;
        }
        delete tmp;
      }
    }
    return root;
  }
};
// @lc code=end
