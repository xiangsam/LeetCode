/*
 * @lc app=leetcode.cn id=2386 lang=cpp
 *
 * [2386] 找出数组的第 K 大和
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <priority_queue>
using namespace std;
// @lc code=start
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long total = 0;
        int n = nums.size();
        for(int i =0; i < n; ++i){
            if(nums[i] >= 0)
                total += nums[i];
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        long long kMinTotal = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.emplace(nums[0], 0);
        for(int sn = 2; sn <= k; ++sn){
            auto [tot, i] = pq.top();
            pq.pop();
            kMinTotal = tot;
            if(i == n - 1)// 已经到最后一个元素
                continue;
            pq.emplace(tot + nums[i+1], i + 1);
            pq.emplace(tot + nums[i+1] - nums[i], i+1);
        }
        return total - kMinTotal;
    }
};
// @lc code=end

