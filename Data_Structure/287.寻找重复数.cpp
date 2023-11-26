/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int findDuplicate1(vector<int> &nums) {
    unordered_set<int> hash;
    for (const auto &e : nums) {
      if (hash.count(e)) {
        return e;
      }
      hash.insert(e);
    }
    return -1;
  }
  int findDuplicate(vector<int> &nums) {
    int slow = 0, fast = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }
    return slow;
  }
};
// @lc code=end
