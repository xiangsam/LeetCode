/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;
// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    queue<char> que;
    unordered_set<char> hash_set;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (!hash_set.contains(s[i])) {
        hash_set.insert(s[i]);
        que.emplace(s[i]);
      } else {
        ans = max(ans, (int)que.size());
        while (que.front() != s[i]) {
          hash_set.erase(que.front());
          que.pop();
        }
        que.pop();
        que.emplace(s[i]);
      }
    }
    ans = max(ans, (int)que.size());
    return ans;
  }
};
// @lc code=end
