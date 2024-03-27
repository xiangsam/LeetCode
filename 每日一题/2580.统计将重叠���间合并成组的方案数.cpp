/*
 * @lc app=leetcode.cn id=2580 lang=cpp
 *
 * [2580] 统计将重叠区间合并成组的方案数
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    long long fastModPow(long long a, long long k, long long mod){
        long long result = 1;
        for(; k != 0; k >>=1){
            if(k & 1){
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
        }
        return result;
    }
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int cnt = 1, end = ranges[0][1];
        for(int i = 1; i < ranges.size(); ++i){
            if(ranges[i][0] <= end){
                end = max(ranges[i][1], end);
            }else{
                end = ranges[i][1];
                ++cnt;
            }
        }
        return fastModPow(2, cnt, 1e9 + 7);
    }
};
// @lc code=end

