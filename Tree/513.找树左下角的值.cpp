/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */
#include <algorithm>
#include <iostream>
#include <utility>
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
  void dfs(TreeNode *node, int depth, bool isLeft, pair<int, int> &record) {
    // 最左由遍历方法决定
    if (node == nullptr) {
      return;
    }
    if (node->left == nullptr && node->right == nullptr) {
      if (depth > record.first) {
        record.first = depth;
        record.second = node->val;
      }
    }
    dfs(node->left, depth + 1, true, record);
    dfs(node->right, depth + 1, false, record);
  }

public:
  int findBottomLeftValue(TreeNode *root) {
    pair<int, int> record(0, root->val);
    dfs(root, 0, false, record);
    return record.second;
  }
};
// @lc code=end
