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

class NumArray2 { // 树状数组
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

  NumArray2(vector<int> &nums) : local_nums(nums), tree(nums.size() + 1, 0) {
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

class NumArray { // 树状数组
  vector<int> tree;
  int n;
  void build(int node, int s, int e, vector<int> &nums) {
    if (s == e) {
      tree[node] = nums[s];
      return;
    }
    int m = s + ((e - s) >> 1);
    build(node * 2 + 1, s, m, nums);
    build(node * 2 + 2, m + 1, e, nums);
    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
  }
  void update_tree(int index, int val, int node, int s, int e) {
    if (s == e) {
      tree[node] = val;
      return;
    }
    int m = s + ((e - s) >> 1);
    if (index <= m) {
      update_tree(index, val, node * 2 + 1, s, m);
    } else {
      update_tree(index, val, node * 2 + 2, m + 1, e);
    }
    tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
  }
  int getSum(int l, int r, int node, int s, int e) {
    int sum = 0;
    if (l <= s && r >= e) {
      return tree[node];
    }
    int m = s + ((e - s) >> 1);
    if (l <= m) {
      sum += getSum(l, r, node * 2 + 1, s, m);
    }
    if (r > m) {
      sum += getSum(l, r, node * 2 + 2, m + 1, e);
    }
    return sum;
  }

public:
  NumArray(vector<int> &nums) : tree(nums.size() * 4, 0), n(nums.size()) {
    build(0, 0, n - 1, nums);
  }

  void update(int index, int val) { update_tree(index, val, 0, 0, n - 1); }

  int sumRange(int left, int right) { return getSum(left, right, 0, 0, n - 1); }
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