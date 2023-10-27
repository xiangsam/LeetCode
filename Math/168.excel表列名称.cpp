/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string convertToTitle(int columnNumber) {
    string ans = "";
    while (columnNumber) {
      columnNumber -= 1;
      int bias = columnNumber % 26;
      ans += ('A' + bias);
      columnNumber /= 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
