/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
#include <iostream>
#include <queue>
#include <vector>
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
  ListNode *merge(ListNode *head1, ListNode *head2) {
    if (head1 == nullptr) {
      return head2;
    }
    if (head2 == nullptr) {
      return head1;
    }
    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);
    q.push(head1);
    q.push(head2);
    ListNode *res = new ListNode(0), *cur = res;
    while (!q.empty()) {
      cur->next = q.top();
      q.pop();
      cur = cur->next;
      if (cur->next) {
        q.push(cur->next);
      }
    }
    return res->next;
  }
  ListNode *mergeSort(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    if (head->next == nullptr) {
      return head;
    }
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *r = mergeSort(slow->next);
    slow->next = nullptr;
    ListNode *l = mergeSort(head);
    ListNode *ans = merge(l, r);
    return ans;
  }
  ListNode *sortList(ListNode *head) { return mergeSort(head); }
};
// @lc code=end
