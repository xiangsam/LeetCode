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
    int best = -1;
    for (int i = n - 1; i >= 0; --i) {
      while (best != -1 && s[best + 1] != s[i]) {
        best = next[best];
      }
      if (s[best + 1] == s[i]) {
        ++best;
      }
    }
    string add = best == n - 1 ? "" : s.substr(best + 1, n);
    reverse(add.begin(), add.end());
    return add + s;
  }
};
// @lc code=end
