/*
 * @Author: Samrito
 * @Date: 2021-11-15 19:08:52
 * @LastEditors: Samrito
 * @LastEditTime: 2022-02-10 11:21:44
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void backtrace(vector<int> &nums, int size, vector<vector<int>> &ans) {
    if (size == nums.size() - 1) {
      ans.push_back(nums);
      return;
    }
    for (int i = size; i < nums.size(); ++i) {
      swap(nums[i], nums[size]);
      backtrace(nums, size + 1, ans);
      swap(nums[i], nums[size]);
    }
  }

public:
  /**
   * @brief backtrace method. nums[0,size] is used, size+1... is not used
   *
   * @Time complexity: O(N! * N)
   *
   * @Space complexity: O(N)
   */
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    backtrace(nums, 0, ans);
    return ans;
  }
};