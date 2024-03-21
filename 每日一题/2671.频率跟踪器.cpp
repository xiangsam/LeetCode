/*
 * @lc app=leetcode.cn id=2671 lang=cpp
 *
 * [2671] 频率跟踪器
 */
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class FrequencyTracker {
private:
    unordered_map<int, int> hashMap;
    unordered_map<int, int> freqCount;
public:
    FrequencyTracker() {

    }
    
    void add(int number) {
        --freqCount[hashMap[number]];
        ++hashMap[number];
        ++freqCount[hashMap[number]];
    }
    
    void deleteOne(int number) {
        if(hashMap[number] == 0){
            return;
        }
        --freqCount[hashMap[number]];
        --hashMap[number];
        ++freqCount[hashMap[number]];
    }
    
    bool hasFrequency(int frequency) {
        return freqCount[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
// @lc code=end

