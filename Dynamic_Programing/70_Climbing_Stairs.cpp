/*
 * @Author: Samrito
 * @Date: 2022-05-04 10:42:55
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-04 10:58:10
 */
#include <bits/stdc++.h>
#include <sys/types.h>
#include <vector>
using namespace std;
class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }
    int a = 1, b = 2;
    int ans = 0;
    for (int i = 3; i <= n; ++i) {
      ans = a + b;
      a = b;
      b = ans;
    }
    return ans;
  }
};