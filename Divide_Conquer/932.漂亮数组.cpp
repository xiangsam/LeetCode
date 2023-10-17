/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * [932] 漂亮数组
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// @lc code=start
class Solution1 {
public:
  vector<int> beautifulArray(int n) {
    vector<int> ret;
    if (n == 1) {
      ret.push_back(1);
      return ret;
    }
    int left_num = int((n + 1) / 2);
    int right_num = int(n / 2);
    vector<int> left = beautifulArray(left_num);
    vector<int> right = beautifulArray(right_num);
    for (auto e : left) {
      e = 2 * e - 1;
      ret.push_back(e);
    }
    for (auto e : right) {
      e = 2 * e;
      ret.push_back(e);
    }
    return ret;
  }
};
class Solution2 { // memoization
public:
  map<int, vector<int>> memo;
  vector<int> beautifulArray(int n) {
    vector<int> ret;
    if (n == 1) {
      ret.push_back(1);
      return ret;
    }
    if (memo.count(n) != 0) {
      return memo[n];
    }
    int left_num = int((n + 1) / 2);
    int right_num = int(n / 2);
    vector<int> left = beautifulArray(left_num);
    vector<int> right = beautifulArray(right_num);
    for (auto e : left) {
      e = 2 * e - 1;
      ret.push_back(e);
    }
    for (auto e : right) {
      e = 2 * e;
      ret.push_back(e);
    }
    memo[n] = ret;
    return ret;
  }
};
class Solution { // memoization
public:
  vector<int> beautifulArray(int n) { // 动态规划
    vector<vector<int>> dp(n + 1, vector<int>());
    dp[1].push_back(1);
    for (int i = 2; i <= n; ++i) {
      int left_num = int((i + 1) / 2);
      int right_num = int(i / 2);
      for (auto e : dp[left_num]) {
        dp[i].push_back(2 * e - 1);
      }
      for (auto e : dp[right_num]) {
        dp[i].push_back(2 * e);
      }
    }
    return dp[n];
  }
};
// @lc code=end
