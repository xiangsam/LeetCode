/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <deque>
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class LRUCache {
  list<pair<int, int>> cache;                              // (key, value)
  unordered_map<int, list<pair<int, int>>::iterator> hash; // key->iterator
  int capacity;

public:
  LRUCache(int capacity) : capacity(capacity) {}

  int get(int key) {
    auto itr = hash.find(key);
    if (itr == hash.end()) {
      return -1;
    }
    cache.splice(cache.begin(), cache, itr->second);
    return itr->second->second;
  }

  void put(int key, int value) {
    auto itr = hash.find(key);
    if (itr != hash.end()) {
      itr->second->second = value;
      cache.splice(cache.begin(), cache, itr->second);
      return;
    }
    cache.insert(cache.begin(), make_pair(key, value));
    hash[key] = cache.begin();
    if (cache.size() > capacity) {
      hash.erase(cache.back().first);
      cache.pop_back();
    }
    return;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
