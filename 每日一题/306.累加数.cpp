/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for(int secondStart = 1; secondStart < n-1; ++secondStart){
            if(num[0] == '0' && secondStart != 1){
                break;
            }
            for(int secondEnd = secondStart; secondEnd < n-1; ++secondEnd){
                if(num[secondStart] == '0' && secondEnd != secondStart){
                    break;
                }
                if(check(secondStart, secondEnd, num)){
                    return true;
                }
            }
        }
        return false;
    }
    bool check(int secondStart, int secondEnd, string num){
        int n = num.size();
        int firstStart = 0, firstEnd = secondStart - 1;
        while(secondEnd <= n-1){
            string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
            int thirdStart = secondEnd + 1, thirdEnd = thirdStart + third.size()-1;
            if(thirdEnd >= n || !(num.substr(thirdStart, third.size()) == third)){
                return false;
            }
            if(thirdEnd == n-1){
                return true;
            }
            firstStart = secondStart;
            firstEnd = secondEnd;
            secondStart = thirdStart;
            secondEnd = thirdEnd;
        }
        return false;
    }
    string stringAdd(string s, int firstStart, int firstEnd, int secondStart, int secondEnd){
        string third = "";
        int cur = 0, flag = 0; // flag记录进位
        while(firstEnd >= firstStart || secondEnd >= secondStart){
            cur = flag;
            if(firstEnd >= firstStart){
                cur += s[firstEnd] - '0';
                --firstEnd;
            }
            if(secondEnd >= secondStart){
                cur += s[secondEnd] - '0';
                --secondEnd;
            }
            flag = cur / 10;
            cur = cur % 10;
            third.push_back(cur + '0');
        }
        if(flag){
            third.push_back(flag + '0');
        }
        reverse(third.begin(), third.end());
        return third;
    }
};
// @lc code=end

