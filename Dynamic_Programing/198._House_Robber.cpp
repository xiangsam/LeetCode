/*
 * @Author: Samrito
 * @Date: 2022-05-05 10:46:43
 * @LastEditors: Samrito
 * @LastEditTime: 2022-05-05 10:57:44
 */
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int rob(vector<int> &nums) {
    int length = nums.size();
    vector<int> money(length, 0);
    if (length == 1) {
      return nums[0];
    } else if (length == 2) {
      return max(nums[0], nums[1]);
    }
    money[0] = nums[0];
    money[1] = max(money[0], nums[1]);
    for (int i = 2; i < length; ++i) {
      money[i] = max(money[i - 1], money[i - 2] + nums[i]);
    }
    return money[length - 1];
  }
};