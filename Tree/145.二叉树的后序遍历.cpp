/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
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
  vector<int> postorderTraversal1(TreeNode *root) {
    stack<TreeNode *> stk;
    TreeNode *ptr = root;
    vector<int> ans;
    unordered_map<TreeNode *, bool> visited;
    while (ptr || !stk.empty()) {
      while (ptr) {
        stk.emplace(ptr);
        visited[ptr] = false;
        ptr = ptr->left;
      }
      while (!stk.empty() && visited[stk.top()]) {
        ans.emplace_back(stk.top()->val);
        stk.pop();
      }
      if (!stk.empty()) {
        ptr = stk.top()->right;
        visited[stk.top()] = true;
      }
    }
    return ans;
  }
  vector<int> postorderTraversal(TreeNode *root) {
    stack<TreeNode *> stk;
    vector<int> ans;
    TreeNode *ptr = root;
    while (ptr || !stk.empty()) {
      while (ptr) {
        ans.emplace_back(ptr->val);
        stk.emplace(ptr->left);
        ptr = ptr->right;
      }
      ptr = stk.top();
      stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
