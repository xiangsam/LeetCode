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
class NumArray1 { // 树状数组
  vector<int> local_nums;
  vector<int> tree;
  int lowbit(int x) { return x & (-x); }
  void add(int index, int val) {
    while (index <= local_nums.size()) { // tree.size() = local_nums.size()+1
      tree[index] += val;
      index += lowbit(index);
    }
  }
  int prefixSum(int index) {
    int sum = 0;
    while (index > 0) {
      sum += tree[index];
      index -= lowbit(index);
    }
    return sum;
  }

public:
  NumArray1(vector<int> &nums) : local_nums(nums), tree(nums.size() + 1, 0) {
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
class NumArray { // 线段树
  int n;
  vector<int> tree;
  void build(int s, int e, int node, vector<int> &nums) {
    if (s == e) {
      tree[node] = nums[s];
      return;
    }
    int m = s + ((e - s) >> 1);
    build(s, m, node * 2 + 1, nums);
    build(m + 1, e, node * 2 + 2, nums);
    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
  }
  void update_tree(int index, int val, int s, int e, int node) {
    if (s == e) {
      tree[node] = val;
      return;
    }
    int m = s + ((e - s) >> 1);
    if (index <= m) {
      update_tree(index, val, s, m, node * 2 + 1);
    } else {
      update_tree(index, val, m + 1, e, node * 2 + 2);
    }
    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
  }
  int prefixSum(int l, int r, int s, int e, int node) {
    if (l <= s && r >= e) {
      return tree[node];
    }
    int sum = 0;
    int m = s + ((e - s) >> 1);
    if (l <= m) {
      sum += prefixSum(l, r, s, m, node * 2 + 1);
    }
    if (r > m) {
      sum += prefixSum(l, r, m + 1, e, node * 2 + 2);
    }
    return sum;
  }

public:
  NumArray(vector<int> &nums) : n(nums.size()), tree(4 * n, 0) {
    build(0, n - 1, 0, nums);
  }

  void update(int index, int val) { update_tree(index, val, 0, n - 1, 0); }

  int sumRange(int left, int right) {
    return prefixSum(left, right, 0, n - 1, 0);
  }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

// int main() {
//   vector<int> a = {-28, -39, 53, 65, 11, -56, -65, -39, -43, 97};
//   NumArray opt(a);
//   cout << opt.sumRange(5, 6) << endl;
//   opt.update(9, 27);
//   cout << opt.sumRange(2, 3) << endl;
//   cout << opt.sumRange(6, 7) << endl;
//   opt.update(1, -82);
//   opt.update(3, -72);
//   cout << opt.sumRange(3, 7) << endl;
//   cout << opt.sumRange(1, 8) << endl;
//   opt.update(5, 13);
//   opt.update(4, -67);
//   return 0;
// }