/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  bool isPowerOfThree1(int n) {
    if (n == 0) {
      return false;
    }
    if (n == 1) {
      return true;
    }
    if (n % 3 == 0) {
      return isPowerOfThree(n / 3);
    }
    return false;
  }
  bool isPowerOfThree(int n) { // 不用递归
    while (n && n % 3 == 0) {
      n /= 3;
    }
    return n == 1;
  }
  bool isPowerOfThree2(int n) { // 不使用循环或递归
    // 数据范围为 |n| < 2^31 - 1, 其中最大的3的幂次为3^19=1162261467
    return n > 0 && 1162261467 % n == 0;
  }
};
// @lc code=end
