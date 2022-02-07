/*
 * @Author: Samrito
 * @Date: 2021-11-15 19:08:52
 * @LastEditors: Samrito
 * @LastEditTime: 2022-01-26 19:42:09
 */
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> next;
        for(const auto &w : wordList){
            dict.insert(w);
        }
        if(!dict.count(endWord)){
            return ans;
        }
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{beginWord}, q2{endWord};
        bool reversed = false, found = false;
        while(!q1.empty()){
            unordered_set<string> q;
            for(const auto &w : q1){
                string s = w;
                for(size_t i = 0; i < s.size(); ++i){
                    char ch = s[i];
                    for(int j = 0; j < 26; ++j){
                        s[i] = j + 'a';
                        if(q2.count(s)){
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found  = true;
                        }
                        if(dict.count(s)){
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            q.insert(s);
                        }
                    }
                    s[i] = ch;
                }
            }
            if(found){
                break;
            }
            for(const auto &w : q){
                dict.erase(w);
            }
            if(q.size() <= q2.size()){
                q1 = q;
            }else{
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
        }
        if(found){
            vector<string> path = {beginWord};
            backtracking(beginWord, endWord, next, path, ans);
        }
        return ans;
    }
    void backtracking(const string &src, const string &dst, unordered_map<string, vector<string>> &next, vector<string> &path, vector<vector<string>> &ans){
        if(src == dst){
            ans.push_back(path);
            return;
        }
        for(const auto &s : next[src]){
            path.push_back(s);
            backtracking(s, dst, next, path, ans);
            path.pop_back();
        }
    }
};