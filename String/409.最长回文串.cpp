/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  int longestPalindrome(string s) {
    bool use_single_axis = false; // 中间轴可以放单个字母
    unordered_map<char, int> hash_map;
    for (const auto &e : s) {
      ++hash_map[e];
    }
    int ans = 0;
    for (const auto &[k, v] : hash_map) {
      if (v % 2 == 0) {
        ans += v;
      } else {
        if (!use_single_axis) {
          ans += v;
          use_single_axis = true;
        } else {
          ans += (v - 1);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
