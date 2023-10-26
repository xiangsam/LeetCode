/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] 链表随机节点
 */
#include <cstdlib>
#include <iostream>
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
 **/

class Solution1 {
  ListNode *list;
  int num;

public:
  Solution1(ListNode *head) : list(head), num(0) {
    ListNode *ptr = head;
    while (ptr != nullptr) {
      ++num;
      if (ptr->next == nullptr) {
        break;
      }
      ptr = ptr->next;
    }
  }

  int getRandom() {
    cout << num << endl;
    int rand_num = rand() % num;
    ListNode *ptr = list;
    while (rand_num && ptr != nullptr) {
      ptr = ptr->next;
      --rand_num;
    }
    if (ptr != nullptr) {
      return ptr->val;
    } else {
      return -1; // or some other value to indicate an error
    }
  }
};

class Solution { //水库算法:
                 //便利列表，对第m个链表元素，结果有1/m概率覆盖之前的节点选择
                 //最终每个元素都是等可能被选择: 1/m * (m)/(m+1) * ... *(n-1)/n
                 //= 1/n
  ListNode *list;

public:
  Solution(ListNode *head) : list(head) {}

  int getRandom() {
    int ans = list->val;
    ListNode *ptr = list->next;
    int m = 2;
    while (ptr != nullptr) {
      if (rand() % m == 0) {
        ans = ptr->val;
      }
      ++m;
      ptr = ptr->next;
    }
    return ans;
  }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
