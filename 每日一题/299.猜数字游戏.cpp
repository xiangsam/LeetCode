/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> secretMap;
        unordered_map<char, int> guessMap;
        int A=0, B=0;
        int n = secret.size();
        for(int i = 0; i < n; ++i){
            if(secret[i] == guess[i]){
                ++A;
            }else{
                ++secretMap[secret[i]];
                ++guessMap[guess[i]];
            }
        }
        for(int i = 0; i < 10; ++i){
            B += min(secretMap['0'+i], guessMap['0'+i]);
        }
        string ans = to_string(A)+"A"+to_string(B)+"B";
        return ans;
    }
};
// @lc code=end

