/*
 * @lc app=leetcode.cn id=292 lang=cpp
 *
 * [292] Nim 游戏
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canWinNim1(int n) {
        vector<int> canWin(n+1, 0);
        for(int i = 0; i <=3 && i <= n; ++i){
            canWin[i] = 1;
        }
        for(int i = 4; i <= n; ++i){
            if(canWin[i-1] == -1 || canWin[i-2] == -1 || canWin[i-3] == -1)//此时可以控制使得后手到之前先手的必败情况
                canWin[i] = 1;
            else
                canWin[i] = -1;
        }
        return canWin[n] == 1;
    }   
    bool canWinNim(int n) {
        return n % 4 > 0;
    } 
};
// @lc code=end

