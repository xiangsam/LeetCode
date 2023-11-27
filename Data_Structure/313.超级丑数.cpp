/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */
#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  //   int nthSuperUglyNumber(int n, vector<int> &primes) {
  //     priority_queue<int, vector<int>, greater<int>> min_heap;
  //     min_heap.emplace(1);
  //     int ans = 0;
  //     while (n) {
  //       int cur = min_heap.top();
  //       min_heap.pop();
  //       if (cur == ans) {
  //         continue;
  //       }
  //       ans = cur;
  //       for (const auto &e : primes)
  //       {//计算由当前丑数产生的新丑数，加到最小堆中排列
  //         if (cur < INT_MAX / e) {
  //           min_heap.emplace(e * cur);
  //         } else {
  //           break;
  //         }
  //       }
  //       --n;
  //     }
  //     return ans;
  //   }
  int nthSuperUglyNumber(int n, vector<int> &primes) {
    // 每个素数（在primes数组中）对应一个索引（在indices数组中）。这个索引指示了该素数已经乘过的最大的超级丑数的位置。以此来避免重复运算，而且确保下一个超级丑数总是正确的增长顺序。
    // 具体来说，当我们在计算第i个超级丑数时，indices数组告诉我们每个素数现在应该与uglies数组中哪一个已知超级丑数相乘。换句话说，indices[j]
    // 表示对于第j个素数，下一个将要使用的乘数是uglies[indices[j]]。
    vector<long> uglies(n, INT_MAX);
    int primes_num = primes.size();
    vector<int> indices(primes_num, 0); // uglies[0]不需要任意primes参与
    uglies[0] = 1;
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < primes_num; ++j) {
        uglies[i] = min(uglies[i], uglies[indices[j]] * primes[j]);
      }
      for (int j = 0; j < primes_num; ++j) {
        if (uglies[i] == uglies[indices[j]] * primes[j]) {
          ++indices[j]; // 防止计算相同的超级丑数
        }
      }
    }
    return (int)uglies[n - 1];
  }
};
// @lc code=end
