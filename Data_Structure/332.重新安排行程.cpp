/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<string> findItinerary1(vector<vector<string>> &tickets) {
    vector<string> ans;
    stack<string> s;
    unordered_map<string, multiset<string>> hash;
    for (auto &e : tickets) {
      hash[e[0]].insert(e[1]);
    }
    s.push("JFK");
    while (!s.empty()) {
      string next = s.top();
      if (hash[next].empty()) {
        ans.push_back(next);
        s.pop();
      } else {
        s.emplace(*(hash[next].begin()));
        hash[next].erase(hash[next].begin());
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    vector<string> ans;
    stack<string> s;
    unordered_map<string,
                  priority_queue<string, vector<string>, greater<string>>>
        hash;
    for (auto &e : tickets) {
      hash[e[0]].emplace(e[1]);
    }
    s.push("JFK");
    while (!s.empty()) {
      string next = s.top();
      if (hash[next].empty()) {
        ans.push_back(next);
        s.pop();
      } else {
        s.emplace(hash[next].top());
        hash[next].pop();
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
