/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
  int hammingDistance(int x, int y) {
    int diff = x ^ y;
    int ans = 0;
    while (diff) {
      ans += diff & 1;
      diff >>= 1;
    }
    return ans;
  }
};
// @lc code=end
