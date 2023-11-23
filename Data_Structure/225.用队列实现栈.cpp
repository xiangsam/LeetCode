/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <iostream>
#include <queue>
using namespace std;
// @lc code=start
class MyStack {
public:
  queue<int> q1, q2;
  MyStack() {}

  void push(int x) { q1.emplace(x); }

  int pop() {
    while (q1.size() > 1) {
      int e = q1.front();
      q2.emplace(e);
      q1.pop();
    }
    int ans = q1.front();
    q1.pop();
    swap(q1, q2);
    return ans;
  }

  int top() {
    while (q1.size() > 1) {
      int e = q1.front();
      q2.emplace(e);
      q1.pop();
    }
    int ans = q1.front();
    q1.pop();
    q2.emplace(ans);
    swap(q1, q2);
    return ans;
  }

  bool empty() { return q1.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
