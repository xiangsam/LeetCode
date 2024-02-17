/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void bfs(Node * root, vector<vector<int>> &ans){
        if(root == nullptr)
            return;
        queue<Node *> nodeQueue;
        nodeQueue.emplace(root);
        while(!nodeQueue.empty()){
            vector<int> tmp;
            int n = nodeQueue.size();
            for(int i = 0; i < n; ++i){
                Node * ptr = nodeQueue.front();
                nodeQueue.pop();
                tmp.emplace_back(ptr->val);
                for(const auto & node : ptr->children){
                    nodeQueue.emplace(node);
                }
            }
            ans.emplace_back(tmp);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        bfs(root, ans);
        return ans;
    }
};
// @lc code=end

