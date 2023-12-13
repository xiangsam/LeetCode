/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */
#include <cstddef>
#include <iostream>
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
class Solution1 {
public:
  bool isPalindrome(ListNode *head) {
    vector<int> val;
    while (head) {
      val.emplace_back(head->val);
      head = head->next;
    }
    int first = 0, last = val.size() - 1;
    while (first <= last) {
      if (val[first] == val[last]) {
        ++first;
        --last;
      } else {
        return false;
      }
    }
    return true;
  }
};
class Solution2 {
  ListNode *frontPointer;

public:
  bool recursiveCheck(ListNode *currentPointer) {
    // 通过递归对链表进行反向
    if (currentPointer != nullptr) {
      if (!recursiveCheck(currentPointer->next)) {
        return false;
      }
      if (currentPointer->val != frontPointer->val) {
        return false;
      }
      frontPointer = frontPointer->next;
    }
    return true;
  }
  bool isPalindrome(ListNode *head) {
    frontPointer = head;
    return recursiveCheck(head);
  }
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    slow->next = reserveList(slow->next);
    ListNode *tail = slow->next, *front = head;
    while (tail) {
      if (tail->val != front->val) {
        return false;
      }
      tail = tail->next;
      front = front->next;
    }
    return true;
  }
  ListNode *reserveList1(ListNode *head) {
    // 返回最后的链表的指针
    ListNode *prev = nullptr, *next;
    while (head) {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
  ListNode *reserveList(ListNode *head, ListNode *prev = nullptr) {
    // 返回最后的链表的指针
    if (head == nullptr) {
      return prev;
    }
    ListNode *next = head->next;
    head->next = prev;
    return reserveList(next, head);
  }
};
// @lc code=end
