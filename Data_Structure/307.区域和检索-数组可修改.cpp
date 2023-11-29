/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class NumArray1 { // TLE
  vector<int> local_nums;
  vector<int> psum;

public:
  NumArray1(vector<int> &nums) : local_nums(nums), psum(nums.size() + 1, 0) {
    partial_sum(nums.begin(), nums.end(), psum.begin() + 1);
  }

  void update(int index, int val) {
    int difference = val - local_nums[index];
    local_nums[index] = val;
    for (int i = index; i < local_nums.size(); ++i) {
      psum[i + 1] += difference;
    }
  }

  int sumRange(int left, int right) { return psum[right + 1] - psum[left]; }
};

class NumArray { // 树状数组
  vector<int> local_nums;
  vector<int> tree;

public:
  int lowbit(int x) { return x & (-x); }
  void add(int index, int val) {
    while (index < tree.size()) {
      tree[index] += val;
      index += lowbit(index); // 包含关系的父节点
    }
  }
  int prefixSum(int index) {
    int sum = 0;
    while (index > 0) {
      sum += tree[index];
      index -=
          lowbit(index); // 当前tree[index]管辖为[index - lowbit(index)+1,index]
    }
    return sum;
  }

  NumArray(vector<int> &nums) : local_nums(nums), tree(nums.size() + 1, 0) {
    for (int i = 0; i < nums.size(); ++i) {
      add(i + 1, nums[i]);
    }
  }

  void update(int index, int val) {
    add(index + 1, val - local_nums[index]);
    local_nums[index] = val;
  }

  int sumRange(int left, int right) {
    return prefixSum(right + 1) - prefixSum(left);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
