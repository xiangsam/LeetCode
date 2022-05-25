/*
 * @Author: Samrito
 * @Date: 2022-05-25 08:33:46
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-25 09:19:29
 */
#include <bits/stdc++.h>
#include <climits>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
  int minSteps(int n) {
    if (n == 1) {
      return 0;
    }
    vector<int> dp(n + 1, INT_MAX - 1);
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
      dp[i] = i; //只复制一次
      int uplimit = i / 2;
      for (int j = 2; j <= uplimit; ++j) {
        if (i % j == 0) {
          dp[i] =
              min(dp[i],
                  dp[j] + i / j); // dp[j] + 1 + i/j - 1：复制1次，粘贴i/j - 1次
        }
      }
    }
    return dp[n];
  }
  int minSteps2(int n) {
    if (n == 1) {
      return 0;
    }
    int ans = 0;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;
    vector<int> prime;
    for (int i = 2; i <= n; ++i) { //埃氏筛
      if (is_prime[i]) {
        prime.push_back(i);
        for (int j = 2 * i; j <= n; j += i) {
          is_prime[j] = false;
        }
      }
    }
    for (auto &e : prime) {
      while (n % e == 0) {
        ans += e;
        n /= e;
      }
    }
    return ans;
  }
};