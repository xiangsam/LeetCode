/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
 */
#include <iostream>
#include <unordered_set>
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
  void in_dfs(TreeNode *root, unordered_set<int> &res) {
    if (root == nullptr) {
      return;
    }
    in_dfs(root->left, res);
    res.insert(root->val);
    in_dfs(root->right, res);
  }
  bool findTarget(TreeNode *root, int k) {
    unordered_set<int> node_set;
    in_dfs(root, node_set);
    for (const auto &e : node_set) {
      if (e != k - e && node_set.contains(k - e)) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
