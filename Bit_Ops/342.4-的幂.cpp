/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */
#include <bitset>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isPowerOfFour1(int n) {
    if (n <= 0) {
      return false;
    }
    while (n % 4 == 0) {
      n = n / 4;
    }
    return n == 1;
  }
  bool isPowerOfFour(int n) {
    if (n <= 0) {
      return false;
    }
    // 二进制奇数位为1的uint: 01010...101 = 1431655765
    return (n & (n - 1)) == 0 && (n & 1431655765);
  }
};
// @lc code=end
