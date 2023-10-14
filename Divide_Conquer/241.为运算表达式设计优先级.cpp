/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> diffWaysToCompute1(string expression) {
    vector<int> ret;
    for (int i = 0; i < expression.length(); ++i) {
      char c = expression[i];
      if (c == '-' || c == '+' || c == '*') {
        vector<int> left = diffWaysToCompute(expression.substr(0, i));
        vector<int> right = diffWaysToCompute(expression.substr(i + 1));
        for (const int &l : left) {
          for (const int &r : right) {
            if (c == '-') {
              ret.push_back(l - r);
            } else if (c == '+') {
              ret.push_back(l + r);
            } else if (c == '*') {
              ret.push_back(l * r);
            }
          }
        }
      }
    }
    if (ret.empty()) {
      ret.push_back(stoi(expression));
    }
    return ret;
  }
  vector<int> diffWaysToCompute(string expression) {
    vector<int> data;
    vector<char> ops;
    int num = 0;
    char op = ' ';
    istringstream ss(expression + "+");
    while (ss >> num && ss >> op) {
      data.push_back(num);
      ops.push_back(op);
    }
    int n = data.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>()));
    for (int i = 0; i < n; ++i) {
      for (int j = i; j >= 0; --j) {
        if (j == i) {
          dp[j][i].push_back(data[i]);
        } else {
          for (int k = j; k < i; ++k) {
            for (auto &left : dp[j][k]) {
              for (auto &right : dp[k + 1][i]) {
                if (ops[k] == '-') {
                  dp[j][i].push_back(left - right);
                } else if (ops[k] == '+') {
                  dp[j][i].push_back(left + right);
                } else if (ops[k] == '*') {
                  dp[j][i].push_back(left * right);
                }
              }
            }
          }
        }
      }
    }
    return dp[0][n - 1];
  }
};
// @lc code=end
