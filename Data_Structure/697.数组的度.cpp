/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findShortestSubArray1(vector<int> &nums) {

    int n = nums.size();
    if (n == 1) {
      return 1;
    }
    unordered_map<int, int> hash;
    for (const auto &e : nums) {
      ++hash[e];
    }
    vector<pair<int, int>> hash_vec(hash.begin(), hash.end());

    sort(hash_vec.begin(), hash_vec.end(),
         [](const auto &a, const auto &b) { return a.second > b.second; });
    int ans = n + 1, idx = 0;

    while (idx < hash_vec.size() &&
           hash_vec[0].second == hash_vec[idx].second) {
      int target = hash_vec[idx].first;
      int left = -1, right = -1;
      for (int i = 0; i < n; ++i) {
        if (nums[i] == target) {
          if (left == -1) {
            left = i;
            right = left;
          } else {
            right = i;
          }
        }
      }
      ans = min(right - left + 1, ans);
      ++idx;
    }
    return ans;
  }
  int findShortestSubArray(vector<int> &nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> hash; // (key, [count, left, right])
    for (int i = 0; i < n; ++i) {
      if (hash.find(nums[i]) != hash.end()) {
        ++hash[nums[i]][0];
        hash[nums[i]][2] = i;
      } else {
        hash[nums[i]] = {1, i, i};
      }
    }
    int degree = 0, ans = 0;
    for (const auto &[_, e] : hash) {
      if (degree < e[0]) {
        degree = e[0];
        ans = e[2] - e[1] + 1;
      } else if (degree == e[0]) {
        ans = min(ans, e[2] - e[1] + 1);
      }
    }
    return ans;
  }
};
// @lc code=end
