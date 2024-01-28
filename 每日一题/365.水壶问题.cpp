/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */
#include <iostream>
#include <unordered_set>
#include <pair>
// @lc code=start
class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        stack<pair<int, int>> stk;
        stk.emplace(0, 0);
        auto hashfunc = [](const pair<int,int> &o){return hash<int>()(o.first) ^ hash<int>()(o.second);};
        unordered_set<pair<int, int>, decltype(hashfunc)> used(0, hashfunc);
        while(!stk.empty()){
            if(used.contains(stk.top())){
                stk.pop();
                continue;
            }
            used.emplace(stk.top());
            auto [remainX, remainY] = stk.top();
            stk.pop();
            if(remainX == targetCapacity || remainY == targetCapacity || remainX + remainY == targetCapacity){
                return true;
            }
            stk.emplace(0, remainY); // 倒掉X
            stk.emplace(remainX, 0); // 倒掉Y
            stk.emplace(jug1Capacity, remainY); // 灌满X
            stk.emplace(remainX, jug2Capacity); // 灌满Y
            stk.emplace(remainX - min(remainX, jug2Capacity - remainY), remainY + min(remainX, jug2Capacity-remainY)); // X倒入Y
            stk.emplace(remainX + min(remainY, jug1Capacity - remainX), remainY - min(remainY, jug1Capacity - remainX)); // Y倒入X
        }
    return false;
    }
};
// @lc code=end

