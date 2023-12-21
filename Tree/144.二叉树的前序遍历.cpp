/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <iostream>
#include <stack>
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
  vector<int> ans;

public:
  void preorderDFS(TreeNode *root) {
    if (root == nullptr) {
      return;
    }
    ans.emplace_back(root->val);
    preorderDFS(root->left);
    preorderDFS(root->right);
  }
  vector<int> preorderTraversal1(TreeNode *root) {
    preorderDFS(root);
    return ans;
  }
  vector<int> preorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return ans;
    }
    stack<TreeNode *> stk;
    stk.emplace(root);
    while (!stk.empty()) {
      TreeNode *top = stk.top();
      stk.pop();
      ans.emplace_back(top->val);
      if (top->right) {
        stk.emplace(top->right);
      }
      if (top->left) {
        stk.emplace(top->left);
      }
    }
    return ans;
  }
};
// @lc code=end
