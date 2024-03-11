/*
 * @lc app=leetcode.cn id=2129 lang=cpp
 *
 * [2129] 将标题首字母大写
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string capitalizeTitle(string title) {
        istringstream iss(title);
        string ans, s;
        while(iss >> s){
            if(!ans.empty()){
                ans += ' ';
            }
            if(s.length() > 2){
                ans += toupper(s[0]);
                s = s.substr(1);
            }
            for(const auto & c : s){
                ans += tolower(c);
            }
        }
        return ans;
    }
};
// @lc code=end

