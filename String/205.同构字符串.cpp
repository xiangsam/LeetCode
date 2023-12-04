/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isIsomorphic1(string s, string t) {
    int len = s.size();
    unordered_map<char, char> hash_map1;
    unordered_map<char, char> hash_map2;
    for (int i = 0; i < len; ++i) {
      if (hash_map1.contains(s[i]) && hash_map1[s[i]] != t[i]) {
        return false;
      }
      if (hash_map2.contains(t[i]) && hash_map2[t[i]] != s[i]) {
        return false;
      }
      hash_map1[s[i]] = t[i];
      hash_map2[t[i]] = s[i];
    }
    return true;
  }
  bool isIsomorphic(string s, string t) {
    vector<int> s_first_index(256, 0), t_first_index(256, 0);
    for (int i = 0; i < s.length(); ++i) {
      if (s_first_index[s[i]] != t_first_index[t[i]]) {
        return false;
      }
      s_first_index[s[i]] = t_first_index[t[i]] = i + 1;
    }
    return true;
  }
};
// @lc code=end
