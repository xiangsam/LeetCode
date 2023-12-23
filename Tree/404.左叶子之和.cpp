/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
  void sumDFS(TreeNode *root, int &sum, bool isLeft) {
    if (root == nullptr) {
      return;
    }
    if (root->left == nullptr && root->right == nullptr && isLeft) {
      sum += root->val;
      return;
    }
    sumDFS(root->left, sum, true);
    sumDFS(root->right, sum, false);
  }
  int sumOfLeftLeaves(TreeNode *root) {
    int sum = 0;
    sumDFS(root, sum, false);
    return sum;
  }
};
// @lc code=end
