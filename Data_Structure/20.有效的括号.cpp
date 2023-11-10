/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    stack<char> stack;
    for (const char &c : s) {
      if (stack.empty()) {
        stack.emplace(c);
      } else {
        if (stack.top() == '(' && c == ')') {
          stack.pop();
        } else if (stack.top() == '[' && c == ']') {
          stack.pop();
        } else if (stack.top() == '{' && c == '}') {
          stack.pop();
        } else {
          stack.emplace(c);
        }
      }
    }
    return stack.empty();
  }
};
// @lc code=end
