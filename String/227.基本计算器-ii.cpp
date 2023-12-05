/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
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
    stack<char> opt;
    stack<int> nums;
    string num;
    for (const auto &e : s) {
      if (e == ' ') {
        continue;
      } else if (e == '+' || e == '-' || e == '*' || e == '/') {
        nums.emplace(stoi(num));
        num = "";
        if (e == '+' || e == '-') {
          caculate(nums, opt);
        }
        if (e == '*' || e == '/') {
          while (!opt.empty() && (opt.top() == '/' || opt.top() == '*')) {
            // 由于特殊的除法，对2* 5 / 3这种情况，需要先进行*再进行/
            int r = nums.top();
            nums.pop();
            int l = nums.top();
            nums.pop();
            char op = opt.top();
            opt.pop();
            switch (op) {
            case '*':
              nums.emplace(l * r);
              break;
            case '/':
              nums.emplace(l / r);
              break;
            }
          }
        }
        opt.emplace(e);
      } else {
        num += e;
      }
    }
    if (num != "") {
      nums.emplace(stoi(num));
    }
    caculate(nums, opt);
    return nums.top();
  }
  void caculate(stack<int> &nums, stack<char> &opt) {
    while (!opt.empty()) {
      int r = nums.top();
      nums.pop();
      int l = nums.top();
      nums.pop();
      char op = opt.top();
      opt.pop();
      switch (op) {
      case '*':
        nums.emplace(l * r);
        break;
      case '/':
        nums.emplace(l / r);
        break;
      case '-':
        nums.emplace(l - r);
        break;
      case '+':
        nums.emplace(l + r);
        break;
      }
    }
  }
};
// @lc code=end
