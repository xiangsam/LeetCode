/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maximumSwap1(int num) {
    if (num == 0) {
      return num;
    }
    int maxDigit = -1;
    string strNum = "";
    vector<pair<int, int>> partialMax; // num-position
    int pos = 0;
    int i = 0;
    while (num) {
      int digit = num % 10;
      num /= 10;
      strNum += '0' + digit;
      if (maxDigit == -1) {
        maxDigit = digit;
        partialMax.emplace_back(maxDigit, pos);
      } else {
        if (maxDigit >= digit) {
          partialMax.emplace_back(maxDigit, pos);
        } else {
          maxDigit = digit;
          pos = i;
          partialMax.emplace_back(maxDigit, pos);
        }
      }
      ++i;
    }
    for (int i = strNum.size() - 1; i >= 0; --i) {
      if (partialMax[i].first != (strNum[i] - '0')) {
        swap(strNum[i], strNum[partialMax[i].second]);
        break;
      }
    }
    reverse(strNum.begin(), strNum.end());
    return stoi(strNum);
  }
  int maximumSwap(int num) {
    if (num == 0) {
      return num;
    }
    string strNum = to_string(num);
    int n = strNum.size();
    int max_i = n - 1;
    vector<int> partialMaxIndex(n);
    for (int i = n - 1; i >= 0; --i) {
      if (strNum[i] > strNum[max_i]) {
        max_i = i;
      }
      partialMaxIndex[i] = max_i;
    }
    for (int i = 0; i < n; ++i) {
      if (strNum[i] != strNum[partialMaxIndex[i]]) {
        swap(strNum[i], strNum[partialMaxIndex[i]]);
        break;
      }
    }
    return stoi(strNum);
  }
};
// @lc code=end
