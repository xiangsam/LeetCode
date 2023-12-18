/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
  int pathSum(TreeNode *root, int targetSum) {
    return root ? pathSumWithRoot(root, targetSum) +
                      pathSum(root->left, targetSum) +
                      pathSum(root->right, targetSum)
                : 0;
  }
  int pathSumWithRoot(TreeNode *root, long long targetSum) {
    if (!root) {
      return 0;
    }
    int count = root->val == targetSum ? 1 : 0;
    count += pathSumWithRoot(root->left, targetSum - root->val);
    count += pathSumWithRoot(root->right, targetSum - root->val);
    return count;
  }
};
// @lc code=end
