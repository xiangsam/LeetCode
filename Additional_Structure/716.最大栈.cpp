/*
 * @lc app=leetcode.cn id=716 lang=cpp
 *
 * [716] 最大栈
 */
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <utility>
using namespace std;
// @lc code=star
class MaxStack1 { // 有问题的实现。单调栈会丢失信息（小于栈顶元素不入栈）
                  // e.g. push 5, push 1, popmax, peekmax
  stack<int> mainStack;
  stack<int> monotonicStack; // 单调递增栈
public:
  MaxStack1() {}

  void push(int x) {
    mainStack.emplace(x);
    if (monotonicStack.empty() || x >= monotonicStack.top()) {
      monotonicStack.emplace(x);
    }
  }

  int pop() {
    int x = mainStack.top();
    mainStack.pop();
    if (x == monotonicStack.top()) {
      monotonicStack.pop();
    }
    return x;
  }

  int top() { return mainStack.top(); }

  int peekMax() { return monotonicStack.top(); }

  int popMax() {
    int x = monotonicStack.top();
    monotonicStack.pop();
    stack<int> tmp;
    while (!mainStack.empty() && mainStack.top() != x) {
      tmp.emplace(mainStack.top());
      mainStack.pop();
    }
    mainStack.pop();
    while (!tmp.empty()) {
      mainStack.emplace(tmp.top());
      tmp.pop();
    }
    return x;
  }
};

class MaxStack2 { // 使用multimap
  list<int> stack;
  multimap<int, list<int>::iterator> map;

public:
  MaxStack2() {}

  void push(int x) {
    stack.push_back(x);
    map.insert(make_pair(x, --stack.end()));
  }

  int pop() {
    int ans = stack.back();
    stack.pop_back();
    auto it = --map.upper_bound(ans);
    map.erase(it);
    return ans;
  }

  int top() { return stack.back(); }

  int peekMax() { return map.rbegin()->first; }

  int popMax() {
    auto it = --map.end();
    int ans = it->first;
    auto stackIt = it->second;
    map.erase(it);
    stack.erase(stackIt);
    return ans;
  }
};

class MaxStack { // 使用set
  set<pair<int, int>> value_count;
  set<pair<int, int>> count_value;
  int cnt;

public:
  MaxStack() : cnt(0) {}

  void push(int x) {
    value_count.emplace(x, cnt);
    count_value.emplace(cnt, x);
  }

  int pop() {
    auto [count, value] = *count_value.rbegin();
    count_value.erase(make_pair(count, value));
    value_count.erase(make_pair(value, count));
    return value;
  }

  int top() {
    auto [count, value] = *count_value.rbegin();
    return value;
  }

  int peekMax() {
    auto [value, count] = *value_count.rbegin();
    return value;
  }

  int popMax() {
    auto [value, count] = *value_count.rbegin();
    value_count.erase(make_pair(value, count));
    count_value.erase(make_pair(count, value));
    return value;
  }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
// @lc code=en