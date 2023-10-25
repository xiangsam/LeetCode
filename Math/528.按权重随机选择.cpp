/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// @lc code=start
class Solution1 {
private:
  vector<int> threshold;
  int max_num;

public:
  Solution1(vector<int> &w) {
    threshold.assign(w.begin(), w.end());
    int n = w.size();
    for (int i = 1; i < n; ++i) {
      threshold[i] = threshold[i] + threshold[i - 1];
    }
    max_num = threshold[n - 1];
  }

  int pickIndex() {
    int num = rand() % max_num;
    int i = 0;
    while (num >= threshold[i]) {
      ++i;
    }
    return i;
  }
};
class Solution {
private:
  vector<int> threshold;
  int max_num;

public:
  Solution(vector<int> &w) : threshold(move(w)) { // 使用库函数
    partial_sum(threshold.begin(), threshold.end(), threshold.begin());
  }

  int pickIndex() {
    int pos = (rand() % threshold.back()) + 1;
    return lower_bound(threshold.begin(), threshold.end(), pos) -
           threshold.begin();
  }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
