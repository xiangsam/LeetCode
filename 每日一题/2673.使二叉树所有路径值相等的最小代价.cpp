/*
 * @lc app=leetcode.cn id=2673 lang=cpp
 *
 * [2673] 使二叉树所有路径值相等的最小代价
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        for(int i = n-1; i >= 2; i-=2){
            ans += abs(cost[i] - cost[i-1]);
            cost[i/2-1] += max(cost[i], cost[i-1]);
        }
        return ans;
    }
};
// @lc code=end

