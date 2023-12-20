/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <iostream>
#include <unordered_map>
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
  TreeNode *dfs(vector<int> &preorder, unordered_map<int, int> &indexMap, int l,
                int r, int rootIndex) {
    if (l > r) {
      return nullptr;
    }
    int rootVal = preorder[rootIndex], inorderRootIndex = indexMap[rootVal];
    int leftTreeLen = inorderRootIndex - l - 1;
    TreeNode *root = new TreeNode(rootVal);
    root->left =
        dfs(preorder, indexMap, l, inorderRootIndex - 1, rootIndex + 1);
    root->right = dfs(preorder, indexMap, inorderRootIndex + 1, r,
                      rootIndex + 2 + leftTreeLen);
    return root;
  }
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) {
      return nullptr;
    }
    unordered_map<int, int> indexMap;
    for (int i = 0; i < inorder.size(); ++i) {
      indexMap[inorder[i]] = i;
    }
    return dfs(preorder, indexMap, 0, preorder.size() - 1, 0);
  }
};
// @lc code=end
