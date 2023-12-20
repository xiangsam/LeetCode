/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */
#include <iostream>
#include <queue>
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
  vector<double> averageOfLevels(TreeNode *root) {
    queue<TreeNode *> nodeQue;
    vector<double> ans;
    nodeQue.emplace(root);
    while (!nodeQue.empty()) {
      int count = nodeQue.size();
      long long valSum = 0;
      for (int i = 0; i < count; ++i) {
        TreeNode *node = nodeQue.front();
        nodeQue.pop();
        valSum += node->val;
        if (node->left) {
          nodeQue.emplace(node->left);
        }
        if (node->right) {
          nodeQue.emplace(node->right);
        }
      }
      ans.emplace_back(double(valSum) / count);
    }
    return ans;
  }
};
// @lc code=end
