/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class RandomizedSet {
  int size;
  list<int> val_list;
  unordered_map<int, list<int>::iterator> hash_map; // val->iterator of val_list
public:
  RandomizedSet() : size(0) {}

  bool insert(int val) {
    if (hash_map.contains(val)) {
      return false;
    }
    auto it = val_list.insert(val_list.begin(), val);
    hash_map[val] = it;
    ++size;
    return true;
  }

  bool remove(int val) {
    if (!hash_map.contains(val)) {
      return false;
    }
    auto it = hash_map[val];
    hash_map.erase(val);
    val_list.erase(it);
    --size;
    return true;
  }

  int getRandom() {
    int idx = rand() % size;
    auto it = val_list.begin();
    advance(it, idx);
    return *it;
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
