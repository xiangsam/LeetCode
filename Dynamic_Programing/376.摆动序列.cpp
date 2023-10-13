/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
// @lc code=start
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int wiggleMaxLength1(vector<int> &nums) { // dp
    int n = nums.size();
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      if (nums[0] != nums[1])
        return 2;
      return 1;
    }
    vector<int> dp(n, 1);
    int start = 1;
    while (nums[0] == nums[start] && start < n) {
      ++start;
    }
    if (start == n) {
      return 1;
    }
    dp[start] = (nums[0] < nums[start]) ? 2 : -2;
    // dp[1] = (nums[0] == nums[1]) ? ((nums[1] < nums[2]) ? -1 : 1)
    //                              : ((nums[0] < nums[1]) ? 2 : -2);
    int max_len = abs(dp[start]);
    for (int i = start + 1; i < n; ++i) {
      for (int j = 1; j <= i - 1; ++j) {
        if (dp[j] * (nums[i] - nums[j]) < 0) {
          dp[i] = max(abs(dp[j]) + 1, abs(dp[i]));
          dp[i] = (nums[j] < nums[i]) ? dp[i] : -dp[i];
        }
      }
      if (dp[i] == 1 && i < n - 1) { // 之前没有合适的摆动序列
        dp[i] = (nums[i] < nums[i + 1]) ? -dp[i] : dp[i];
      }
      max_len = max(abs(dp[i]), max_len);
    }
    return max_len;
  }
  int wiggleMaxLength(vector<int> &nums) { // 贪心, 时间复杂度O(n)
    int n = nums.size();
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      if (nums[0] != nums[1])
        return 2;
      return 1;
    }
    vector<int> seq;
    seq.push_back(nums[0]);
    int start = 1;
    while (seq.back() == nums[start] && start < n) {
      ++start;
    }
    if (start == n) {
      return seq.size();
    }
    bool flag = seq.back() < nums[start]; // true: 前<后; false: 前>后
    seq.push_back(nums[start]);
    for (int i = start + 1; i < n; ++i) {
      if (nums[i] == seq.back()) {
        continue;
      }
      if ((seq.back() < nums[i]) != (flag)) {
        flag = seq.back() < nums[i];
        seq.push_back(nums[i]);
      } else {
        // cout << nums[i] << " " << flag << endl;
        if (flag && nums[i] > seq.back()) {
          seq.pop_back();
          seq.push_back(nums[i]);
        } else if (!flag && nums[i] < seq.back()) {
          seq.pop_back();
          seq.push_back(nums[i]);
        }
      }
    }
    // for (auto &e : seq) {
    //   cout << e << " ";
    // }
    return seq.size();
  }
};
// @lc code=end
