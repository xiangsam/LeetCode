/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
// 2 1 3
// 3 1 2
class Solution {
  unordered_map<int, int> post_value2index;

public:
  TreeNode *construct(vector<int> preorder, vector<int> postorder,
                      int pre_start, int pre_end, int post_start,
                      int post_end) {
    if (pre_start > pre_end) {
      return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[pre_start]);
    if (pre_start == pre_end) {
      return root;
    }
    int index = post_value2index[preorder[pre_start + 1]];
    root->left =
        construct(preorder, postorder, pre_start + 1,
                  pre_start + 1 + index - post_start, post_start, index);
    root->right =
        construct(preorder, postorder, pre_start + 2 + index - post_start,
                  pre_end, index + 1, post_end);
    return root;
  }
  TreeNode *constructFromPrePost(vector<int> &preorder,
                                 vector<int> &postorder) {
    for (int i = 0; i < postorder.size(); ++i) {
      post_value2index[postorder[i]] = i;
    }
    TreeNode *root = construct(preorder, postorder, 0, preorder.size() - 1, 0,
                               postorder.size() - 1);
    return root;
  }
};
// @lc code=end
