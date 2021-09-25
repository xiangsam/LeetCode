#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char, int>counts;
       int max_count = 0;
       for(auto c : s){
           max_count = max(max_count, ++counts[c]);
       }
       vector<vector<char>> buckets(max_count+1);
       for(const auto &p : counts){
           buckets[p.second].push_back(p.first);
       }
       vector<string> ansV;
       for(int i = max_count; i >= 0; --i){
           for(const char &p : buckets[i]){
               ansV.push_back(string(i,p));
           }
       }
       string ans = accumulate(ansV.begin(), ansV.end(),string(""));
       return ans;
    }
};

class Solution2 {
public:
    string frequencySort(string s) {
       unordered_map<char, int>counts;
       for(auto c : s)
           ++counts[c];
       vector<pair<int,char>> ans;
       for(auto element : counts)
           ans.push_back({element.second, element.first});
       sort(ans.begin(),ans.end(), greater<pair<int, char>>());
       string ans_s = "";
       for(auto e : ans){
           ans_s += string(e.first, e.second);
       }
       return ans_s;
    }
};
