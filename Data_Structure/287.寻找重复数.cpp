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
  int findDuplicate2(vector<int> &nums) { // 快慢指针
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
  int findDuplicate(vector<int> &nums) { // 二分查找
    int n = nums.size();
    int l = 1, r = n - 1, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int cnt = 0;
      for (int i = 0; i < n; ++i) {
        cnt += nums[i] <= mid;
      }
      if (cnt <= mid) { // 对目标x,nums中小于等于x的元素个数一定要大于x
        l = mid + 1;
      } else {
        r = mid - 1;
        ans = mid;
      }
    }
    return ans;
  }
};
// @lc code=end
