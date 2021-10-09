#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void backtrace(vector<vector<int>>& ans, vector<int>& nums, int num,int n, int k){
        if(k == 0){
            ans.push_back(nums);
            return;
        }
        for(int i = num; i <= n - k + 1; ++i){
            nums.push_back(i);
            backtrace(ans, nums, i+1, n, k-1);
            nums.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        backtrace(ans, nums, 1, n, k);
        return ans;
    }
};
