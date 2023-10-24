/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string output("");
    int num1_len = num1.size(), num2_len = num2.size();
    if (num1_len < num2_len) {
      swap(num1, num2);
      swap(num1_len, num2_len);
    }
    int addition = 0;
    for (int i = 0; i < num2_len; ++i) {
      int sum = num1[i] - '0' + num2[i] - '0' + addition;
      output += to_string(sum % 10);
      addition = sum < 10 ? 0 : 1;
    }
    for (int i = num2_len; i < num1_len; ++i) {
      int sum = num1[i] - '0' + addition;
      output += to_string(sum % 10);
      addition = sum < 10 ? 0 : 1;
    }
    if (addition) {
      output += "1";
    }
    reverse(output.begin(), output.end());
    return output;
  }
};
// @lc code=end
