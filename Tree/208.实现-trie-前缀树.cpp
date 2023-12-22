/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include <iostream>
#include <string>
#include <tuple>
using namespace std;

// @lc code=start
struct TrieNode {
  bool isVal;
  TrieNode *childNode[26];
  TrieNode() : isVal(false) {
    for (int i = 0; i < 26; ++i) {
      childNode[i] = nullptr;
    }
  }
};
class Trie {
  TrieNode *root;

public:
  Trie() : root(new TrieNode()) {}

  void insert(string word) {
    TrieNode *tp = root;
    for (const auto &e : word) {
      if (tp->childNode[e - 'a'] == nullptr) {
        tp->childNode[e - 'a'] = new TrieNode();
      }
      tp = tp->childNode[e - 'a'];
    }
    tp->isVal = true;
  }

  bool search(string word) {
    TrieNode *tp = root;
    for (const auto &e : word) {
      if (tp->childNode[e - 'a'] == nullptr) {
        return false;
      }
      tp = tp->childNode[e - 'a'];
    }
    return tp->isVal;
  }

  bool startsWith(string prefix) {
    TrieNode *tp = root;
    for (const auto &e : prefix) {
      if (tp->childNode[e - 'a'] == nullptr) {
        return false;
      }
      tp = tp->childNode[e - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
