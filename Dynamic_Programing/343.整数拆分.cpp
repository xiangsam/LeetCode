/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak1(int n) {//均值不等式方法
        if(n == 2){
            return 1;
        }
        int max_mul = 0;
        for(int i = 2; i <= n; ++i){
            int p = int(n / i);
            int q = n - p * (i-1);
            if(q - p > 1){
                int assign = q-p-1;
                max_mul = max(max_mul, int(pow(p, i-1-assign)* pow(p+1, assign) * (q-assign)));
            }
            else
                max_mul = max(max_mul, int(pow(p, i-1) * q));
            if(p == 1){
                break;
            }
        }
        return max_mul;
    }
    int integerBreak(int n) {//动态规划方法
        if(n == 2){
            return 1;
        }
        if(n == 3){
            return 2;
        }
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i = 4; i <=n; ++i){
            dp[i] = max(dp[i-2] * 2, dp[i-3]*3);
        }
        return dp[n];
    }
};
// @lc code=end

