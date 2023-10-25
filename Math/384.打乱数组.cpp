/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 */
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
private:
  vector<int> origin;

public:
  Solution(vector<int> &nums) : origin(move(nums)) {}

  vector<int> reset() { return origin; }

  vector<int> shuffle() {
    if (origin.empty()) {
      return {};
    }
    vector<int> shuffled(origin);
    int n = origin.size();
    for (int i = 0; i < n; ++i) {
      int pos = rand() % (n - i);
      swap(shuffled[i], shuffled[i + pos]);
    }
    return shuffled;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end
