/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */
#include <algorithm>
#include <iostream>
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
  vector<int> depth;

public:
  int getMaxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    int left = getMaxDepth(root->left), right = getMaxDepth(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1) {
      return -1;
    }
    return 1 + max(left, right);
  }
  bool isBalanced(TreeNode *root) { return getMaxDepth(root) != -1; }
};
// @lc code=end
