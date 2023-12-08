/*
 * @lc app=leetcode.cn id=772 lang=cpp
 *
 * [772] 基本计算器 III
 */
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int calculate(string s) {
    stack<int> nums;
    stack<char> opts;
    for (int i = 0; i < s.size(); ++i) {
      if (isdigit(s[i])) {
        string num = "";
        num += s[i];
        while (i + 1 < s.size() && isdigit(s[i + 1])) {
          num += s[i + 1];
          ++i;
        }
        nums.emplace(stoi(num));
      } else if (isOperate(s[i])) {
        while (!opts.empty() && hasPrecendence(opts.top(), s[i])) {
          int r = nums.top();
          nums.pop();
          int l = nums.top();
          nums.pop();
          char opt = opts.top();
          opts.pop();
          nums.emplace(calculate(opt, l, r));
        }
        opts.emplace(s[i]);
      } else if (s[i] == '(') {
        opts.emplace(s[i]);
      } else if (s[i] == ')') {
        while (!opts.empty() && opts.top() != '(') {
          int r = nums.top();
          nums.pop();
          int l = nums.top();
          nums.pop();
          char opt = opts.top();
          opts.pop();
          nums.emplace(calculate(opt, l, r));
        }
        opts.pop();
      }
    }
    while (!opts.empty()) {
      int r = nums.top();
      nums.pop();
      int l = nums.top();
      nums.pop();
      char opt = opts.top();
      opts.pop();
      nums.emplace(calculate(opt, l, r));
    }
    return nums.top();
  }
  int calculate(char opt, int l, int r) {
    int ans = 0;
    switch (opt) {
    case '+':
      ans = l + r;
      break;
    case '-':
      ans = l - r;
      break;
    case '*':
      ans = l * r;
      break;
    case '/':
      ans = l / r;
      break;
    }
    return ans;
  }
  bool isOperate(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
  }
  // check if op1 has higher precendence than op2
  bool hasPrecendence(char op1, char op2) {
    // 一般情况下，左边的表达式op1有着更高的优先级
    if (op1 == '(' || op1 == ')') {
      return false;
    } else if ((op2 == '*' || op2 == '/') && (op1 == '+' || op1 == '-')) {
      return false;
    }
    return true;
  }
};
// @lc code=end
