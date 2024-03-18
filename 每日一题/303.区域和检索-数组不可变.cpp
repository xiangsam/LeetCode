/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// @lc code=start
class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) : prefixSum(nums.size()+1, 0) {
        partial_sum(nums.begin(), nums.end(), prefixSum.begin() + 1);
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

