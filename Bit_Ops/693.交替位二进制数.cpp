/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
  bool hasAlternatingBits(int n) {
    return 0 == ((((uint)n ^ (n >> 1)) + 1) & n);
  }
};
// @lc code=end
