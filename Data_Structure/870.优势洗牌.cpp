/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
    // 选择nums1中相比num2[i]下一个最大值，如果没有，则选择nums1最小值以避免影响其他
    priority_queue<pair<int, int>, vector<pair<int, int>>> max_heap;
    int n = nums2.size();
    for (int i = 0; i < n; ++i) {
      max_heap.emplace(nums2[i], i);
    }
    sort(nums1.begin(), nums1.end());
    int left = 0, right = n - 1;
    vector<int> ans(n, 0);
    while (!max_heap.empty()) {
      auto [val, idx] = max_heap.top();
      max_heap.pop();
      if (nums1[right] > val) {
        ans[idx] = nums1[right--];
      } else {
        ans[idx] = nums1[left++];
      }
    }
    return ans;
  }
};
// @lc code=end
