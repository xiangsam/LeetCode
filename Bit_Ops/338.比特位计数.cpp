/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> countBits1(int n) {
    vector<int> ans(n + 1, 0);
    if (n == 0) {
      return ans;
    }
    ans[1] = 1;
    int mask = 0;
    for (int i = 2; i <= n; ++i) {
      if ((i & (i - 1)) == 0) {
        mask = i - 1;
      }
      //   cout << n << " " << i << " " << mask << endl;
      ans[i] = 1 + ans[i & mask];
    }
    return ans;
  }
  vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      ans[i] = (i & 1) ? ans[i - 1] + 1 : ans[i >> 1];
    }
    return ans;
  }
};
// @lc code=end
