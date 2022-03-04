/*
 * @Author: Samrito
 * @Date: 2022-02-07 20:02:11
 * @LastEditors: Samrito
 * @LastEditTime: 2022-03-04 23:18:14
 */
#include <algorithm>
#include <bits/stdc++.h>
#include <hash_map>
#include <iostream>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using namespace __gnu_cxx;
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    set<vector<int>> ans;
    vector<int> comb = {};
    sort(candidates.begin(), candidates.end());
    backtrace(ans, comb, candidates, 0, target, 0);
    return vector<vector<int>>(ans.begin(), ans.end());
  }
  void backtrace(set<vector<int>> &ans, vector<int> &comb,
                 vector<int> &candidates, int index, int target, int sum) {
    if (sum >= target) {
      if (sum == target) {
        ans.insert(comb);
      }
      return;
    }
    for (int i = index; i < candidates.size(); ++i) {
      if (sum + candidates[i] > target)
        break;
      comb.push_back(candidates[i]);
      backtrace(ans, comb, candidates, i + 1, target, sum + candidates[i]);
      comb.pop_back();
      while (
          i > 0 && candidates[i] == candidates[i - 1] &&
          i < candidates.size() - 1 &&
          candidates[i] ==
              candidates
                  [i +
                   1]) { // 从递归结束的角度取消后面的重复结果，若后面的元素与刚刚用过的元素相同，则只是之前情况的一个子集
        i++;
      }
    }
  }
};
class Solution2 {
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    set<vector<int>> ans;
    vector<int> comb = {};
    sort(candidates.begin(), candidates.end());
    backtrace(ans, comb, candidates, 0, target, 0);
    return vector<vector<int>>(ans.begin(), ans.end());
  }
  void backtrace(set<vector<int>> &ans, vector<int> &comb,
                 vector<int> &candidates, int index, int target, int sum) {
    if (sum >= target) {
      if (sum == target) {
        ans.insert(comb);
      }
      return;
    }
    for (int i = index; i < candidates.size(); ++i) {
      if (candidates[i] + sum > target)
        break;
      if (i > index &&
          candidates[i] ==
              candidates
                  [i -
                   1]) // 从当前进入的递归角度考虑，避免选择相同的元素进入递归
        continue;
      comb.push_back(candidates[i]);
      backtrace(ans, comb, candidates, i + 1, target, sum + candidates[i]);
      comb.pop_back();
    }
  }
};
int main() {
  vector<int> candidates = {2, 5, 2, 1, 2};
  int target = 5;
  vector<vector<int>> ans = (new Solution)->combinationSum2(candidates, target);
  for (const auto e : ans) {
    for (const auto i : e) {
      cout << i << ' ';
    }
    cout << '\n';
  }
  return 0;
}