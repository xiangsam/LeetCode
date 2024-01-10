/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
public:
  void in_dfs(TreeNode *root, vector<int> &ans) {
    if (root == nullptr) {
      return;
    }
    in_dfs(root->left, ans);
    ans.emplace_back(root->val);
    in_dfs(root->right, ans);
    return;
  }
  vector<int> inorderTraversal1(TreeNode *root) {
    // 递归实现
    vector<int> ans;
    in_dfs(root, ans);
    return ans;
  }
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> stk;
    vector<int> ans;
    TreeNode *ptr = root;
    while (ptr || !stk.empty()) {
      while (ptr) {
        stk.emplace(ptr);
        ptr = ptr->left;
      }
      ptr = stk.top();
      stk.pop();
      ans.emplace_back(ptr->val);
      ptr = ptr->right;
    }
    return ans;
  }
};
// @lc code=end
