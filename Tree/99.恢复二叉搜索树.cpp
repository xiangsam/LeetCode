/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */
#include <algorithm>
#include <cstddef>
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
class Solution1 {
public:
  void inorderDFS(TreeNode *root, vector<int> &ans) {
    if (root == nullptr) {
      return;
    }
    if (root->left) {
      inorderDFS(root->left, ans);
    }
    ans.emplace_back(root->val);
    if (root->right) {
      inorderDFS(root->right, ans);
    }
  }
  void buildDFS(TreeNode *root, vector<int> &ans, int &index) {
    if (root == nullptr) {
      return;
    }
    if (root->left) {
      buildDFS(root->left, ans, index);
    }
    root->val = ans[index++];
    if (root->right) {
      buildDFS(root->right, ans, index);
    }
  }
  void recoverTree(TreeNode *root) {
    vector<int> ans;
    inorderDFS(root, ans);
    sort(ans.begin(), ans.end());
    int index = 0;
    buildDFS(root, ans, index);
  }
};
class Solution {
public:
  void inorderDFS(TreeNode *root, TreeNode *&prev, TreeNode *&mistake1,
                  TreeNode *&mistake2) {
    if (root == nullptr) {
      return;
    }
    if (root->left) {
      inorderDFS(root->left, prev, mistake1, mistake2);
    }
    if (prev && root->val <= prev->val) {
      if (!mistake1) {
        mistake1 = prev;
        mistake2 = root;
      } else {
        mistake2 = root;
      }
    }
    prev = root;
    if (root->right) {
      inorderDFS(root->right, prev, mistake1, mistake2);
    }
  }
  void recoverTree(TreeNode *root) {
    // 中序遍历时二分查找树会得到一个升序数组，找到非升错误位置即可
    // 只有两个节点被错误交换，或者是相邻，或者是不相邻
    TreeNode *prev = nullptr, *mistake1 = nullptr, *mistake2 = nullptr;
    inorderDFS(root, prev, mistake1, mistake2);
    if (mistake1 && mistake2) {
      int temp = mistake1->val;
      mistake1->val = mistake2->val;
      mistake2->val = temp;
    }
  }
};

// @lc code=end
