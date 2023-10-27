/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string ans = "";
    int len_a = a.size(), len_b = b.size();
    if (len_a < len_b) {
      swap(a, b);
      swap(len_a, len_b);
    }
    int addition = 0;
    for (int i = 0; i < len_b; ++i) {
      int add = a[i] - '0' + b[i] - '0' + addition;
      ans += (add % 2 + '0');
      addition = add / 2;
    }
    for (int i = len_b; i < len_a; ++i) {
      int add = addition + (a[i] - '0');
      ans += (add % 2 + '0');
      addition = add / 2;
    }
    if (addition) {
      ans += (addition + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
