/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */
#include <iostream>
#include <queue>
#include <stack>
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
struct CMP {
  bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
};
class Solution {
public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    priority_queue<ListNode *, vector<ListNode *>, CMP> q;
    for (auto list : lists) {
      if (list) {
        q.push(list); // 第一个元素加入最小堆
      }
    }
    ListNode *ans = new ListNode(0), *cur = ans;
    while (!q.empty()) {
      cur->next = q.top();
      q.pop();
      cur = cur->next;
      if (cur->next) {
        q.push(cur->next); // 增加列表后一个元素入堆
      }
    }
    return ans->next;
  }
};
// @lc code=end
