/*
 * @lc app=leetcode.cn id=2642 lang=cpp
 *
 * [2642] 设计可以求最短路径的图类
 */
#include <iostream>
#include <vector>
#include <priority_queue>
#include <pair>
// @lc code=start
class Graph {
private:
    vector<vector<pair<int, int>>> graph;
public:
    Graph(int n, vector<vector<int>>& edges) {
        graph = vector<vector<pair<int, int>>>(n);
        for(const auto & edge : edges){
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(graph.size(), INT_MAX);
        distance[node1] = 0;
        pq.emplace(0, node1);
        while(!pq.empty()){
            auto [cost, cur] = pq.top();
            pq.pop();
            if(cur == node2){
                return cost;
            }
            for(auto [next, nextCost] : graph[cur]){
                if(distance[next] > cost + nextCost){
                    distance[next] = cost + nextCost;
                    pq.emplace(cost + nextCost, next);
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
// @lc code=end

