/*
 * @lc app=leetcode.cn id=2670 lang=cpp
 *
 * [2670] 找出不同元素数目差数组
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> prefix, suffix;
        for(const auto & e : nums){
            suffix[e]++;
        }
        vector<int> diff(n, 0);
        for(int i = 0; i < n; ++i){
            prefix[nums[i]]++;
            suffix[nums[i]]--;
            if(suffix[nums[i]] == 0){
                suffix.erase(nums[i]);
            }
            diff[i]  = prefix.size() -  suffix.size();
        }
        return diff;
    }
};
// @lc code=end

