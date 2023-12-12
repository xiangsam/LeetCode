/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
  ListNode *swapPairs1(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *p = head, *s;
    if (p && p->next) {
      s = p->next;
      p->next = s->next;
      s->next = p;
      head = s;
      while (p->next && p->next->next) {
        s = p->next->next;
        p->next->next = s->next;
        s->next = p->next;
        p->next = s;
        p = s->next;
      }
    }
    return head;
  }
  ListNode *swapPairs2(ListNode *head) {
    ListNode *dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode *p = dummyHead;
    while (p->next && p->next->next) {
      ListNode *node1 = p->next;
      ListNode *node2 = p->next->next;
      p->next = node2;
      node1->next = node2->next;
      node2->next = node1;
      p = node1;
    }
    ListNode *ans = dummyHead->next;
    delete dummyHead;
    return ans;
  }
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
  }
};
// @lc code=end
