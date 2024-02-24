/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void in_dfs(TreeNode* root, vector<int>& nodeList){
        if(root == nullptr)
            return;
        in_dfs(root->left, nodeList);
        nodeList.emplace_back(root->val);
        in_dfs(root->right, nodeList);
        delete root;
    }
    void binary_search1(vector<int> nodeList, int query, int begin, int end, vector<int>& min_max){
        if(begin > end)
            return;
        int mid = begin + (end - begin)/2;
        if(nodeList[mid] == query){
            min_max[0] = query;
            min_max[1] = query;
            return;
        }else if(nodeList[mid] > query){
            min_max[1] = nodeList[mid];
            binary_search1(nodeList, query, begin, mid-1, min_max);
        }else{
            min_max[0] = nodeList[mid];
            binary_search1(nodeList, query, mid+1, end, min_max);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nodeList;
        in_dfs(root, nodeList);
        vector<vector<int>> ans(queries.size(), vector<int>(2, -1));
        int n = nodeList.size();
        for(int i = 0; i < queries.size(); ++i){
            int begin = 0, end = n-1, query = queries[i];
            int mid;
            while(begin <= end){
                mid = begin + (end - begin) / 2;
                if(nodeList[mid] == query){
                    ans[i][0] = ans[i][1] = query;
                    break;
                }
                else if(nodeList[mid] > query){
                    ans[i][1] = nodeList[mid];
                    end = mid-1;
                }else{
                    ans[i][0] = nodeList[mid];
                    begin = mid+1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

