/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> hash_map;
    for (const auto &e : s) {
      ++hash_map[e];
    }
    for (const auto &e : t) {
      --hash_map[e];
    }
    for (const auto &[key, val] : hash_map) {
      if (val != 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
