/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int longestConsecutive1(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int max_len = 1, len = 1;
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
      if (nums[i] == nums[i - 1] + 1) {
        ++len;
      } else if (nums[i] == nums[i - 1]) {
        continue;
      } else {
        len = 1;
      }
      max_len = max(max_len, len);
    }
    return max_len;
  }
  int longestConsecutive(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    unordered_set<int> hash;
    for (const auto e : nums) {
      hash.insert(e);
    }
    int ans = 0;
    while (!hash.empty()) {
      int cur = *(hash.begin());
      hash.erase(cur);
      int next = cur + 1, prev = cur - 1;
      while (hash.count(next)) {
        hash.erase(next++);
      }
      while (hash.count(prev)) {
        hash.erase(prev--);
      }
      ans = max(next - prev - 1, ans);
    }
    return ans;
  }
};
// @lc code=end
