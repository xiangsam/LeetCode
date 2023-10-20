/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string convertToBase7(int num) {
    if (num == 0)
      return "0";
    bool negtive = num < 0;
    if (negtive)
      num = -num;
    string ans;
    while (num) {
      // a = num / 7, b = num % 7
      int a = num / 7, b = num % 7;
      ans = to_string(b) + ans;
      num = a;
    }
    return negtive ? "-" + ans : ans;
  }
};
// @lc code=end
