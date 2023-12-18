/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <iostream>
#include <type_traits>
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
    bool checkSymmetric(TreeNode *node_l, TreeNode *node_r){
        if(node_l == nullptr && node_r == nullptr){
            return true;
        }
        else if(node_l && node_r){
            return (node_l->val == node_r->val) && checkSymmetric(node_l->left, node_r->right) && checkSymmetric(node_l->right ,node_r->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode *root) {
        return checkSymmetric(root, root);
    }

};
// @lc code=end
