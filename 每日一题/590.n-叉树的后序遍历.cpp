/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */
#include <iostream>
#include <vector>
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
    void postDFS(Node * root, vector<int> &ans){
        if(root == nullptr)
            return;
        for(const auto & node: root->children){
            postDFS(node, ans);
        }
        ans.emplace_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postDFS(root, ans);
        return ans;
    }
};
// @lc code=end

