#include <__utility/pair.h>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    set<vector<int>> ans;
    backtracing(nums, 0, ans);
    return vector<vector<int>>(ans.begin(), ans.end());
  }
  void backtracing(vector<int> &nums, int level, set<vector<int>> &ans) {
    if (level == nums.size() - 1) {
      ans.insert(nums);
      return;
    }
    for (int i = level; i < nums.size(); i++) {
      if (i == level || nums[level] != nums[i]) {
        swap(nums[level], nums[i]);
        backtracing(nums, level + 1, ans);
        swap(nums[level], nums[i]);
      } else {
        continue;
      }
    }
  }
};