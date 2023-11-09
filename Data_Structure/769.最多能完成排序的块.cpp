/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxChunksToSorted(vector<int> &arr) {
    // 如果可以分块，则左边所有元素最大值小于等于右边所有元素的最小值
    int nums = arr.size();
    vector<int> leftMax(nums, 0), rightMin(nums, 0);
    leftMax[0] = arr[0];
    rightMin[nums - 1] = arr[nums - 1];
    for (int i = 1; i < nums; ++i) {
      leftMax[i] = max(leftMax[i - 1], arr[i]);
    }
    for (int i = nums - 2; i >= 0; --i) {
      rightMin[i] = min(rightMin[i + 1], arr[i]);
    }
    int ans = 1;
    for (int i = 0; i < nums - 1; ++i) {
      if (leftMax[i] <= rightMin[i + 1]) {
        ++ans;
      }
    }
    return ans;
  }
};
// @lc code=end
