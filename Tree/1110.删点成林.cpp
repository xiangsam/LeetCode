/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
class Solution1 {
  unordered_set<int> targets;
  vector<TreeNode *> ans;

public:
  void dfs(TreeNode *root) {
    // 不删除节点，需要额外判断子节点是否在删除状态中
    if (root == nullptr) {
      return;
    }
    dfs(root->left);
    dfs(root->right);
    if (targets.contains(root->val)) {
      if (root->left && !targets.contains(root->left->val)) {
        ans.emplace_back(root->left);
      }
      if (root->right && !targets.contains(root->right->val)) {
        ans.emplace_back(root->right);
      }
    }
    if (root->left && targets.contains(root->left->val)) {
      root->left = nullptr;
    }
    if (root->right && targets.contains(root->right->val)) {
      root->right = nullptr;
    }
  }
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    // 先处理完子节点，再处理当前节点，避免断开链接导致遍历问题
    for (const auto &e : to_delete) {
      targets.insert(e);
    }
    dfs(root);
    if (!targets.contains(root->val)) {
      ans.emplace_back(root);
    }
    return ans;
  }
};
class Solution {
  unordered_set<int> targets;
  vector<TreeNode *> ans;

public:
  TreeNode *dfs(TreeNode *root) {
    // 删除节点，判断子节点是否为null即可
    if (root == nullptr) {
      return root;
    }
    root->left = dfs(root->left);
    root->right = dfs(root->right);
    if (targets.contains(root->val)) {
      if (root->left) {
        ans.emplace_back(root->left);
      }
      if (root->right) {
        ans.emplace_back(root->right);
      }
      // delete root;
      root = nullptr;
    }
    return root;
  }
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    // 先处理完子节点，再处理当前节点，避免断开链接导致遍历问题
    for (const auto &e : to_delete) {
      targets.insert(e);
    }
    root = dfs(root);
    if (root) {
      ans.emplace_back(root);
    }
    return ans;
  }
};

// @lc code=end
