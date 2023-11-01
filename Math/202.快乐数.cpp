/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <iostream>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
  bool isHappy1(int n) { //  集合记录
    set<int> his;
    his.insert(n);
    while (true) {
      int sum = 0;
      while (n) {
        int b = n % 10;
        sum += b * b;
        n /= 10;
      }
      if (sum == 1) {
        return true;
      }
      if (his.count(sum)) {
        return false;
      }
      his.insert(sum);
      n = sum;
    }
  }
  bool isHappy(int n) { // 快慢指针
    // 一定会有循环，循环在1则是快乐数，此时必然在1相遇
    int fast = n, slow = n;
    do {
      slow = next(slow);
      fast = next(fast);
      fast = next(fast);
    } while (fast != slow);
    return (slow == 1);
  }
  int next(int n) {
    int res = 0;
    while (n) {
      int b = n % 10;
      res += b * b;
      n = n / 10;
    }
    return res;
  }
};
// @lc code=end
