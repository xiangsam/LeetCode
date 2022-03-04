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
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
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
class Solution {
public:
  void dfs(TreeNode *node, vector<string> &ans, string path) {
    if (node == nullptr) {
      return;
    }
    path += to_string(node->val);
    if (node->left == nullptr && node->right == nullptr) {
      ans.push_back(path);
      return;
    }
    path += "->";
    dfs(node->left, ans, path);
    dfs(node->right, ans, path);
  }
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    string path = "";
    dfs(root, ans, path);
    return ans;
  }
};