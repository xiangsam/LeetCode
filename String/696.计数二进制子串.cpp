/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int countBinarySubstrings1(string s) {
    int ans = 0;
    vector<int> match(s.size(), -1);
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] != s[i - 1]) {
        match[i] = i - 1;
        ++ans;
      } else if (match[i - 1] != -1 && s[i] == s[i - 1] && match[i - 1] > 0) {
        if (s[i] != s[match[i - 1] - 1]) {
          match[i] = match[i - 1] - 1;
          ++ans;
        }
      }
    }
    return ans;
  }
  int countBinarySubstrings(string s) {
    int pre = 0, cur = 1, ans = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        ++cur;
      } else {
        pre = cur;
        cur = 1;
      }
      if (pre >= cur) {
        ++ans;
      }
    }
    return ans;
  }
};
// @lc code=end
