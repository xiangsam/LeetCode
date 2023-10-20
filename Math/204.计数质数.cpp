/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int countPrimes1(int n) { // 埃式筛
    if (n < 2) {
      return 0;
    }
    vector<bool> isPrime(n, true);
    int count = n - 2; // 排除0，1
    for (int i = 2; i <= sqrt(n); ++i) {
      if (isPrime[i]) {
        for (int j = 2 * i; j < n; j += i) {
          if (isPrime[j]) {
            isPrime[j] = false;
            --count;
          }
        }
      }
    }
    return count;
  }
  int countPrimes(int n) { // 埃式筛, 优化
    if (n <= 2) {
      return 0;
    }
    vector<bool> isPrime(n, true);
    int count = int(n / 2);     // 只考虑奇数，1对应素数2
    int i = 3, sqrtn = sqrt(n); // i 是当前质数
    while (i <= sqrtn) {
      // i 的倍数已经被循环标记为非质数，从i*i开始
      for (int j = i * i; j < n; j += 2 * i) { //避免偶数和重复
        // i*i, (i+2)*i, (i+5) * i
        // (i-2) * i这样的奇数已经被上一轮(i-2)*(i-2), (i-2)*i, ... 标记
        if (isPrime[j]) {
          isPrime[j] = false;
          count--;
        }
      }
      do {
        i += 2;
      } while (i <= sqrtn && !isPrime[i]); //避免偶数和重复
    }
    return count;
  }
};
// @lc code=end
