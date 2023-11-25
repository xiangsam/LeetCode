/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findLHS(vector<int> &nums) {
    unordered_map<int, int> hash;
    for (const auto &e : nums) {
      ++hash[e];
    }
    int ans = 0;
    for (const auto &[key, value] : hash) {
      if (hash.find(key + 1) != hash.end()) {
        ans = max(ans, hash[key + 1] + hash[key]);
      }
    }
    return ans;
  }
};
// @lc code=end
