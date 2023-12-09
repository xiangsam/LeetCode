/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

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
class Solution {
public:
  ListNode *reverseList1(ListNode *head) {
    // 非递归
    ListNode *prev = nullptr, *next;
    while (head) {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
  ListNode *reverseList(ListNode *head, ListNode *prev = nullptr) {
    // 递归
    if (!head) {
      return prev;
    }
    ListNode *next = head->next;
    head->next = prev;
    return reverseList(next, head);
  }
};
// @lc code=end
