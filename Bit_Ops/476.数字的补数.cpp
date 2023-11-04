/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
  int findComplement1(int num) {
    int mask = 0;
    uint inverse = ~uint(num);
    while (num) {
      mask = (mask << 1) + 1;
      num >>= 1;
    }
    return mask & inverse;
  }
  int findComplement(int num) {
    int mask = 1;
    while (mask < num) {
      mask = (mask << 1) + 1;
    }
    return mask ^ num;
  }
};
// @lc code=end
