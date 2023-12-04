/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  int countSubstrings(string s) {
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      ans += help(s, i, i);     // 当前字符为中间线
      ans += help(s, i, i + 1); // 两字符间为中间线
    }
    return ans;
  }
  int help(string s, int l, int r) {
    int count = 0;
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      ++count;
      --l;
      ++r;
    }
    return count;
  }
};
// @lc code=end
