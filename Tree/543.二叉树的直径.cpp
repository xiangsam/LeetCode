/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
  int ans;

public:
  int maxEdgeLenght(TreeNode *root) {
    if (root == nullptr) {
      return -1;
    }
    int leftLength = maxEdgeLenght(root->left) + 1;
    int rightLength = maxEdgeLenght(root->right) + 1;
    ans = max(ans, leftLength + rightLength);
    return max(leftLength, rightLength);
  }
  int diameterOfBinaryTree(TreeNode *root) {
    // 一定是经过某个树节点折向
    ans = -1;
    maxEdgeLenght(root);
    return ans;
  }
};
// @lc code=end
