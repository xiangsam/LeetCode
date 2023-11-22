/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int subarraySum1(vector<int> &nums, int k) { // 时间复杂度O(n^2)，TLE
    int n = nums.size();
    vector<int> psum(n + 1, 0);
    int ans = 0;
    partial_sum(nums.begin(), nums.end(), psum.begin() + 1);
    for (int i = 0; i < n; ++i) {
      {
        for (int j = i; j < n; ++j) {
          if (psum[j + 1] - psum[i] == k) {
            ++ans;
          }
        }
      }
    }
    return ans;
  }
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    int ans = 0, psum = 0;
    unordered_map<int, int> hashMap;
    hashMap[0] = 1;
    for (auto &e : nums) {
      psum += e;
      if (hashMap.find(psum - k) != hashMap.end()) {
        ans += hashMap[psum - k];
      }
      ++hashMap[psum];
      // This is important because there can be multiple
      // subarrays that end at different points in the array
      // but have the same sum.
    }
    return ans;
  }
};
// @lc code=end
