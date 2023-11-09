/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class MinStack {
  // 额外使用一个栈，记录大小信息(单个变量不足以使getMin为O(1))
  stack<int> stk, min_stk;

public:
  MinStack() {}

  void push(int val) {
    stk.push(val);
    if (min_stk.empty() || min_stk.top() >= val) {
      min_stk.push(val);
    }
  }

  void pop() {
    if (!min_stk.empty() && min_stk.top() == stk.top()) {
      min_stk.pop();
    }
    stk.pop();
  }

  int top() { return stk.top(); }

  int getMin() { return min_stk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
