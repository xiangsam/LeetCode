/*
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
using namespace std;
// @lc code=start
class AllOne {
  list<pair<string, int>> cache;
  unordered_map<string, list<pair<string, int>>::iterator> hash_map;

public:
  AllOne() {}

  void inc(string key) {
    if (!hash_map.contains(key)) {
      cache.emplace_back(make_pair(key, 1));
      auto it = cache.end();
      advance(it, -1);
      hash_map[key] = it;
      return;
    }
    auto it = hash_map[key];
    ++it->second;
    auto it2 = it;
    while (it2->second <= it->second && it2 != cache.begin()) {
      advance(it2, -1);
    }
    // splice 是将it插到it2之前，因此迭代出现it2对应值大于it对应值，需要回退it2
    if (it2->second > it->second) {
      advance(it2, 1);
    }
    cache.splice(it2, cache, it);
    return;
  }

  void dec(string key) {
    auto it = hash_map[key];
    if (it->second == 1) {
      cache.erase(it);
      hash_map.erase(key);
      return;
    }
    --it->second;
    auto it2 = it;
    while (it2->second >= it->second && it2 != cache.end()) {
      advance(it2, 1);
    }
    cache.splice(it2, cache, it);
    return;
  }

  string getMaxKey() {
    if (cache.empty()) {
      return "";
    }
    return cache.front().first;
  }

  string getMinKey() {
    if (cache.empty()) {
      return "";
    }
    return cache.back().first;
  }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
