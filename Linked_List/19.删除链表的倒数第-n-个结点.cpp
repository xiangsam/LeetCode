/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */
#include <cstddef>
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
  ListNode *findNthFromEnd(ListNode *head, int &count) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *node = findNthFromEnd(head->next, count);
    --count;
    if (count == 0) {
      return head;
    }
    return node;
  }
  ListNode *removeNthFromEnd1(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int count = n + 1;
    ListNode *p = findNthFromEnd(dummy, count);
    ListNode *target = p->next;
    p->next = target->next;
    delete target;
    return dummy->next;
  }
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *front = dummy, *tail = dummy;
    while (n--) {
      tail = tail->next;
    }
    while (tail->next != nullptr) {
      front = front->next;
      tail = tail->next;
    }
    ListNode *target = front->next;
    front->next = target->next;
    delete target;
    return dummy->next;
  }
};
// @lc code=end
