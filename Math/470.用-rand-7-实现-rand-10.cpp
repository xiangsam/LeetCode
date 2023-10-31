/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */
#include <iostream>
using namespace std;
// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
  int rand10() {
    int row, col, idx;
    do {
      col = rand7();
      row = rand7();
      idx = (row - 1) * 7 + col;
    } while (idx > 40);
    return (idx - 1) % 10 + 1;
  }
};
// @lc code=end
