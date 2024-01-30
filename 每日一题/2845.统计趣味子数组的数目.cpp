/*
 * @lc app=leetcode.cn id=2845 lang=cpp
 *
 * [2845] 统计趣味子数组的数目
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        // 记录flag[i] = (nums[i] % modulo ==k)
       long long prefixSum = 0, ans = 0;
       unordered_map<int, int> hash_cnt;
       hash_cnt[0] = 1; // 对0:0区间，此时之前的前缀和为0
       for(const auto & e : nums){
        prefixSum += int(e % modulo == k);
        ans += hash_cnt[(prefixSum + modulo - k) % modulo];
        ++hash_cnt[prefixSum % modulo];
       } 
        return ans;
    }
};
// @lc code=end

