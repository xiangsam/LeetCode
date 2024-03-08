/*
 * @lc app=leetcode.cn id=2834 lang=cpp
 *
 * [2834] 找出美丽数组的最小和
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        int mid = target / 2;
        long long ans = 0;
        if(mid >= n){
            ans += (long long)(1 + n) * n / 2;
            return ans % (long long)(1e9+7);
        }
        ans += (long long)(1 + mid) * mid/ 2;
        if(mid < n){
            long long tail = target + (n - mid) - 1;
            ans += (tail + target) * (tail-target+1) / 2;
        }
        return ans % (long long)(1e9+7);
    }
};
// @lc code=end

