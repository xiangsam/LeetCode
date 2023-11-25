/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string shortestPalindrome(string s) { // KMP字符匹配算法
    int n = s.size();
    vector<int> next(n, -1);
    for (int i = 1; i < n; ++i) {
      int j = next[i - 1];
      while (j != -1 && s[j + 1] != s[i]) {
        j = next[j];
      }
      if (s[j + 1] == s[i]) {
        next[i] = j + 1;
      }
    }
    int match = -1;
    for (int i = n - 1; i >= 0; --i) {
      while (match != -1 && s[i] != s[match + 1]) {
        match = next[match];
      }
      if (s[i] == s[match + 1]) {
        ++match;
      }
    }
    string add = match == n - 1 ? "" : s.substr(match + 1, n);
    reverse(add.begin(), add.end());
    return add + s;
  }
};
// @lc code=end
