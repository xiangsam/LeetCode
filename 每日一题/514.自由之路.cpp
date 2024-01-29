/*
 * @lc app=leetcode.cn id=514 lang=cpp
 *
 * [514] 自由之路
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findRotateSteps1(string ring, string key) {
        // dp[i][j]: 拼出key的第i个字符，ring的第j个字符指向12:00的步数
        // dp[i][j]只有在key[i]与ring[j]相等时才有意义，使用pos[i]表示合法的key[i]合法的j
        // 状态转移：dp[i][j](j\in pos[i]) = min{dp[i-1][k](k\in pos[i-1]) + min{abs{j-k}, n-abs{j-k}}}
        int n = ring.length(), m = key.length();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<vector<int>> pos(26);
        for(int i = 0; i < n; ++i){
            pos[ring[i] - 'a'].emplace_back(i);
        }
        for(const auto idx : pos[key[0] - 'a']){
            dp[0][idx] = min(idx, n-idx);
        }
        for(int i = 1; i < m; ++i){
            for(const auto idx1 : pos[key[i] - 'a']){
                for(const auto idx2 : pos[key[i-1] - 'a']){
                    dp[i][idx1] = min(dp[i][idx1], dp[i-1][idx2] + min(abs(idx2 - idx1), n-abs(idx2 - idx1)));
                }
            }
        }
        int ans = INT_MAX;
        for(const auto idx : pos[key[m-1] - 'a']){
            ans = min(ans, dp[m-1][idx]);
        }
        return ans + m;
    }
    int findRotateSteps(string ring, string key) {
        int n = ring.length(), m = key.length();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        vector<vector<int>> pos(26);
        for(auto i = 0; i < n; ++i){
            pos[ring[i] - 'a'].emplace_back(i);
        }
        for(const auto & idx : pos[key[0] - 'a']){
            dp[0][idx] = min(idx, n - idx);
        }
        for(int i = 1; i < m; ++i){
            for(const auto & idx1 : pos[key[i] - 'a']){
                for(const auto & idx2 : pos[key[i-1] - 'a']){
                    dp[i][idx1] = min(dp[i][idx1], dp[i-1][idx2] + min(abs(idx1 - idx2), n - abs(idx1 - idx2)));
                }
            }
        }
        int ans = INT_MAX;
        for(const auto & idx : pos[key[m-1] - 'a']){
            ans = min(ans, dp[m-1][idx]);
        }
        return ans + m;
    }
};
// @lc code=end

