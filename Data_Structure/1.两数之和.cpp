/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> hash;
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      auto pos = hash.find(target - nums[i]);
      if (pos == hash.end()) {
        hash[nums[i]] = i;
      } else {
        ans.push_back(pos->second);
        ans.push_back(i);
        return ans;
      }
    }
    return ans;
  }
};
// @lc code=end
