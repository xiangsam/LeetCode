/*
 * @Author: Samrito
 * @Date: 2022-05-19 10:16:10
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-19 10:43:10
 */
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    int len = s.size();
    vector<int> nums(len + 1, 0);
    nums[0] = 1; // s[0]不是'0'时为1,因此设置nums[0] = 1
    for (int i = 1; i <= len; ++i) {
      if (s[i - 1] != '0')
        nums[i] = nums[i - 1]; //直接在s[0:i-2]的每个分割集后加上s[i-1]
      if (i >= 2) {
        if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
          nums[i] += nums[i - 2]; //在s[0:i-3]的每个分割集后加上s[i-2:i-1]
        }
      }
    }
    return nums[len];
  }
};