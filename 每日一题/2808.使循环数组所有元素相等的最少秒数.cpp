/*
 * @lc app=leetcode.cn id=2808 lang=cpp
 *
 * [2808] 使循环数组所有元素相等的最少秒数
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumSeconds1(vector<int>& nums) {
        unordered_map<int, vector<int>> hash_map;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            hash_map[nums[i]].emplace_back(i);
        }
        int ans = INT_MAX;
        for(const auto & [num, idx] : hash_map){
            int max_dis = idx[0] + n - idx.back(); // 外圈
            for(int i = 1; i < idx.size(); ++i){
                max_dis = max(max_dis, idx[i] - idx[i-1]);
            }
            ans = min(ans, max_dis / 2);
        }
        return ans;

    }
    int minimumSeconds(vector<int>& nums){
        unordered_map<int, vector<int>> hash_map;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            hash_map[nums[i]].emplace_back(i);
        }
        int ans = INT_MAX;
        for(const auto &[num, idx] : hash_map){
            int max_dis = idx[0] + n - idx.back();
            for(int i = 1; i < idx.size(); ++i){
                max_dis = max(max_dis, idx[i] - idx[i-1]);
            }
            ans = min(ans, max_dis / 2);
        }
        return ans;
    }
};
// @lc code=end

