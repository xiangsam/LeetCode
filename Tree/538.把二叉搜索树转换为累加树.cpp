/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */
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
public:
  void getSum(TreeNode *root, int &sum) {
    if (root == nullptr) {
      return;
    }
    getSum(root->left, sum);
    sum += root->val;
    getSum(root->right, sum);
  }
  void modifyVal(TreeNode *root, int &sum) {
    if (root == nullptr) {
      return;
    }
    modifyVal(root->left, sum);
    int tmp = root->val;
    root->val = sum;
    sum -= tmp;
    modifyVal(root->right, sum);
  }
  TreeNode *convertBST(TreeNode *root) {
    int sum = 0;
    getSum(root, sum);
    modifyVal(root, sum);
    return root;
  }
};
// @lc code=end
