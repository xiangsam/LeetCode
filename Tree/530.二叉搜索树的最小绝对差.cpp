/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */
#include <climits>
#include <cstddef>
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
  void dfs(TreeNode *root, TreeNode *&prev, int &ans) {
    if (root == nullptr) {
      return;
    }
    dfs(root->left, prev, ans);
    if (prev == nullptr) {
      prev = root;
    } else {
      ans = min(ans, root->val - prev->val);
      prev = root;
    }
    dfs(root->right, prev, ans);
  }

public:
  int getMinimumDifference(TreeNode *root) {
    int ans = INT_MAX;
    TreeNode *prev = nullptr;
    dfs(root, prev, ans);
    return ans;
  }
};
// @lc code=end
