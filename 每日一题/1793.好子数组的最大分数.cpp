/*
 * @lc app=leetcode.cn id=1793 lang=cpp
 *
 * [1793] 好子数组的最大分数
 */
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximumScore1(vector<int>& nums, int k) {
        // 使用单调队列维护区间最小值，继承上一长度的队列来每个长度重新建队列时间
        // 依然TLE
        int n = nums.size();
        int min_len = 1;
        deque<int> init_q;
        for(int i = k - min_len + 1; i <= k; ++i){
            while(!init_q.empty() && nums[init_q.back()] > nums[i]){
                init_q.pop_back();
            }
            init_q.push_back(i);
        }
        int ans = INT_MIN;
        for(int len = min_len; len <= n; ++len){
            int begin = max(0, k - len  +1);
            if (k - len + 1 >= 0){
                if(nums[begin] < nums[init_q.front()]){
                    init_q.push_front(begin);
                }
            }else{
                while(!init_q.empty() && nums[init_q.back()] > nums[len-1]){
                    init_q.pop_back();
                }
                init_q.push_back(len-1);
            }
            deque<int> q = init_q;
            // cout << q.front() << endl;
            ans = max(ans, nums[q.front()] * len);
            for(int i = begin+1; i <= min(k, n - len); ++i){
                while(!q.empty() && q.front() < i){
                    q.pop_front();
                }
                while(!q.empty() && nums[q.back()] > nums[i + len-1]){
                    q.pop_back();
                }
                q.push_back(i + len - 1);
                ans = max(ans, nums[q.front()] * len);
                // cout << ans << endl;
            }
            // cout << len << "---" << ans << endl;
        }
        return ans;
    }
    int maximumScore2(vector<int>& nums, int k) {
        // 单调栈方法
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st1, st2;
        for(int i = 0; i < n; ++i){
            while(!st1.empty() && nums[st1.top()] >= nums[i]){
                st1.pop();
            }
            if(!st1.empty()){
                left[i] = st1.top();
            }
            st1.push(i);
        }
        for(int i = n-1; i >= 0; --i){
            while(!st2.empty() && nums[st2.top()] >= nums[i]){
                st2.pop();
            }
            if(!st2.empty()){
                right[i] = st2.top();
            }
            st2.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            // left[i]已经比nums[i]小，以nums[i]为最小的区间不包含left[i]
            if(left[i] + 1 <= k && right[i] - 1 >= k){
                ans = max(ans, nums[i] * (right[i] - left[i] - 1));
            }
        }
        return ans;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[k], min_num = nums[k];
        int l = k, r = k;
        for(int i = 0; i < n-1; ++i){
            // 除了k共n-1未访问位置
            if(r == n-1 || (l > 0 && nums[l-1] > nums[r+1])){
                min_num = min(min_num, nums[--l]);
            }else if(l == 0 || (r < n-1 && nums[r+1] >= nums[l-1])){
                min_num = min(min_num, nums[++r]);
            }
            ans = max(ans, min_num * (r - l + 1));
        }
        return ans;
    }
};
// @lc code=end

