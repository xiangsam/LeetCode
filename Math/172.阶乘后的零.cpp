/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
  int trailingZeroes1(int n) {
    return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
  }
  int trailingZeroes(int n) {
    vector<int> dp(n + 1, 0); // dp[i]: i中因子5的个数
    if (n < 5)
      return 0;
    dp[5] = 1;
    int ret = 1;
    for (int i = 10; i <= n; i += 5) {
      dp[i] = 1 + dp[i / 5];
      ret += dp[i];
    }
    return ret;
  }
};
// @lc code=end
