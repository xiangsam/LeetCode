/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxProduct1(vector<string> &words) {
    int nums = words.size();
    vector<int> bitMask(nums, 0);
    for (int i = 0; i < nums; ++i) {
      for (auto const &c : words[i]) {
        bitMask[i] |= 1 << (c - 'a');
      }
    }
    int ans = 0;
    for (int i = 0; i < nums - 1; ++i) {
      for (int j = i + 1; j < nums; ++j) {
        if ((bitMask[i] & bitMask[j]) == 0) {
          ans = max(ans, int(words[i].size() * words[j].size()));
        }
      }
    }
    return ans;
  }
  int maxProduct(vector<string> &words) {
    //使用hash map映射
    unordered_map<int, int> hash_map; // mask->len
    int ans = 0;
    for (const auto &word : words) {
      int bitMask = 0, len = word.size();
      for (const auto &c : word) {
        bitMask |= 1 << (c - 'a');
      }
      for (const auto &[hash_mask, hash_len] : hash_map) {
        if (!(hash_mask & bitMask)) {
          ans = max(ans, hash_len * len);
        }
      }
      hash_map[bitMask] = max(len, hash_map[bitMask]);
    }
    return ans;
  }
};
// @lc code=end
