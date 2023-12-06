/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int strStr(string haystack, string needle) {
    vector<int> next(needle.size(), -1);
    for (int i = 1; i < needle.size(); ++i) {
      int j = next[i - 1];
      while (j != -1 && needle[j + 1] != needle[i]) {
        j = next[j];
      }
      if (needle[j + 1] == needle[i]) {
        next[i] = j + 1;
      }
    }
    int match = -1;
    for (int i = 0; i < haystack.size(); ++i) {
      while (match != -1 && needle[match + 1] != haystack[i]) {
        match = next[match];
      }
      if (needle[match + 1] == haystack[i]) {
        ++match;
      }
      if (match == needle.size() - 1) {
        return i - needle.size() + 1;
      }
    }
    return -1;
  }
};
// @lc code=end
