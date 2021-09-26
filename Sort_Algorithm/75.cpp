#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
/**
 * @brief use quickSort algorithm
 * @time_complexity O(NlogN)
 */
class Solution {
public:
    void quickSort(vector<int>& nums, int first, int end){
        if(first + 1 >= end)
            return;
        int l = first, r = end - 1, pivot = nums[first];
        while(l < r){
            while(l < r && nums[r] >= pivot) --r;
            while(l < r && nums[l] <= pivot) ++l;
            swap(nums[l], nums[r]);
        }
        swap(nums[l], nums[first]);
        quickSort(nums, first, l);
        quickSort(nums, l+1, end);
    }
    void sortColors(vector<int>& nums) {
       quickSort(nums, 0, nums.size());
    }
};

