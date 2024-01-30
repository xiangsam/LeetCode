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
       //对区间[l, r]，区间值为p[r] - p[l-1]
       // (p[r] - p[l-1]) % modulo == k
       // p[l-1] % modulo == (p[r] - k) % modulo -- 判断条件
       // 对每个p[r]，所有l<=r, 若p[l-1] 满足判断条件，则区间[l, r]符合
       // 使用hash_cnt记录p[l-1] % modulo
       // 对[0, r]，条件为p[r] % modulo == k, 即(p[r]-k) % module == 0
       // 初始设置hash_cnt[0] = 1即可
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

