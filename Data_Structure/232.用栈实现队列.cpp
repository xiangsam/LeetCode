/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <iostream>
#include <stack>
using namespace std;
// @lc code=start
class MyQueue1 {
public:
  stack<int> stk1, stk2;
  MyQueue1() {}

  void push(int x) { stk1.push(x); }

  int pop() {
    // 较为复杂的实现，不需要再从stk2倒回stk1
    //  确保stk1倒到stk2时stk2为空即可
    while (!stk1.empty()) {
      int tmp = stk1.top();
      stk1.pop();
      stk2.push(tmp);
    }
    int res = stk2.top();
    stk2.pop();
    while (!stk2.empty()) {
      int tmp = stk2.top();
      stk2.pop();
      stk1.push(tmp);
    }
    return res;
  }

  int peek() {
    while (!stk1.empty()) {
      int tmp = stk1.top();
      stk1.pop();
      stk2.push(tmp);
    }
    int res = stk2.top();
    while (!stk2.empty()) {
      int tmp = stk2.top();
      stk2.pop();
      stk1.push(tmp);
    }
    return res;
  }

  bool empty() { return stk1.empty(); }
};

class MyQueue {
public:
  stack<int> stk1, stk2;
  MyQueue() {}

  void push(int x) { stk1.push(x); }

  int pop() {
    if (stk2.empty()) {
      while (!stk1.empty()) {
        int tmp = stk1.top();
        stk1.pop();
        stk2.push(tmp);
      }
    }
    int res = stk2.top();
    stk2.pop();
    return res;
  }

  int peek() {
    if (stk2.empty()) {
      while (!stk1.empty()) {
        int tmp = stk1.top();
        stk1.pop();
        stk2.push(tmp);
      }
    }
    int res = stk2.top();
    return res;
  }

  bool empty() { return stk1.empty() && stk2.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
