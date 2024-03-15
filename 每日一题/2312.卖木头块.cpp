/*
 * @lc app=leetcode.cn id=2312 lang=cpp
 *
 * [2312] 卖木头块
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    long long sellingWood1(int m, int n, vector<vector<int>>& prices) {
        // TLE, price过多时第三层循环过长
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        // i, j 作为长度
        int min_h = INT_MAX, min_w = INT_MAX;
        for(const auto & price : prices){
            dp[price[0]][price[1]] = price[2];
            min_h = min(min_h, price[0]);
            min_w = min(min_w, price[1]);
        }
        for(int h = min_h; h < m + 1; ++h){
            for(int w = min_w; w < n + 1; ++w){
                for(const auto & price : prices){
                    if(h < price[0] || w < price[1])
                        continue;
                    dp[h][w] = max(dp[h][w], dp[h - price[0]][w] + dp[price[0]][w]);
                    dp[h][w] = max(dp[h][w], dp[h][w - price[1]] + dp[h][price[1]]);
                }
            }
        }
        return dp[m][n];
    }
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m+1, vector<long long>(n+1, 0));
        int min_h = INT_MAX, min_w = INT_MAX;
        for(const auto & price : prices){
            dp[price[0]][price[1]] = price[2];
            min_h = min(min_h, price[0]);
            min_w = min(min_w, price[1]);
        }
        for(int h = min_h; h < m + 1; ++h){
            for(int w = min_w; w < n + 1; ++w){
                for(int i = 1; i <= h/2; ++i){
                    dp[h][w] = max(dp[h][w], dp[h - i][w] + dp[i][w]);
                }
                for(int j = 1; j <= w/2; ++j){
                    dp[h][w] = max(dp[h][w], dp[h][w-j] + dp[h][j]);
                }
            }
        }
        return dp[m][n];
    }

};
// @lc code=end

