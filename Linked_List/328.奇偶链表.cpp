/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */
#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
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
class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *odd = head, *even = head->next;
    ListNode *dummy = head->next;
    while (true) {
      if (even->next != nullptr) {
        odd->next = even->next;
        odd = odd->next;
      } else {
        odd->next = nullptr; // 避免出现环
        break;
      }
      if (odd->next != nullptr) {
        even->next = odd->next;
        even = even->next;
      } else {
        even->next = nullptr; // 避免出现环
        break;
      }
    }
    odd->next = dummy;
    return head;
  }
};
// @lc code=end
