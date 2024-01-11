/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */
#include <ios>
#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
  ListNode *getMid(ListNode *left, ListNode *right) {
    ListNode *fast = left, *slow = left;
    while (fast != right && fast->next != right) { // 向右取中
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
  TreeNode *buildTree(ListNode *left, ListNode *right) {
    if (left == right) {
      return nullptr;
    }
    ListNode *mid = getMid(left, right);
    TreeNode *root = new TreeNode(mid->val);
    root->left = buildTree(left, mid);
    root->right = buildTree(mid->next, right);
    return root;
  }
  TreeNode *sortedListToBST(ListNode *head) { return buildTree(head, nullptr); }
};
class Solution {
public:
  TreeNode *build(ListNode *&head, int left, int right) {
    if (left > right) {
      return nullptr;
    }
    int mid = (left + right + 1) >> 1;
    TreeNode *root = new TreeNode(0);
    root->left = build(head, left, mid - 1);
    root->val = head->val;
    head = head->next;
    root->right = build(head, mid + 1, right);
    return root;
  }
  TreeNode *sortedListToBST(ListNode *head) {
    ListNode *p = head;
    int length = 0;
    while (p) {
      ++length;
      p = p->next;
    }
    return build(head, 0, length - 1);
  }
};
// @lc code=end
