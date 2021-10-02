#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> & isConnected, int city, int size){
        isConnected[city][city] = 0;
        for(int i = 0; i < size; ++i){
            if(isConnected[city][i] == 1 && isConnected[i][i])
                dfs(isConnected, i, size);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int nums = 0;
        if(n == 0) return 0;
        for(int i = 0; i < n; ++i){
            if(isConnected[i][i]){
                dfs(isConnected, i, n);
                nums++;
            }
        }
        return nums;
    }
};

class Solution2 {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        int nums = 0;
        if(!size) return 0;
        for(int i = 0; i < size; ++i){
            if(isConnected[i][i] == 1){
                nums++;
                stack<int> city;
                city.push(i);
                while(!city.empty()){
                    int j = city.top();
                    isConnected[j][j] = 0;
                    city.pop();
                    for(int k = 0; k < size; ++k){
                        if(isConnected[j][k] && isConnected[k][k])
                            city.push(k);
                    }
                }
            }
        }
        return nums;
    }
};
