#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution {
private:
    vector<int> direction{-1,0,1,0,-1};
public:
    void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 2)
            return;
        if(grid[r][c] == 0){
            points.push({r, c});
            return;
        }
        grid[r][c] = 2;
        for(int i = 0; i < 4; ++i){
            int x = r + direction[i];
            int y = c + direction[i+1];
            dfs(points, grid, x, y);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool dfs_end = false;
        queue<pair<int, int>> points;
        for(int i = 0; i < m; ++i){
            if(dfs_end) break;
            for(int j = 0; j < n; ++j){
                if(grid[i][j]){
                    dfs(points, grid, i, j);
                    dfs_end = true;
                    break;
                }
            }
        }
        int x, y, level = 0;
        while(!points.empty()){
            ++level;
            int n_points = points.size();
            while(n_points--){
                auto [r, c] = points.front();
                points.pop();
                for(int i = 0; i < 4; ++i){
                    x = r + direction[i];
                    y = c + direction[i+1];
                    if(x >= 0 && x < m && y >= 0 && y < n){
                        if(grid[x][y] == 2){
                            continue;
                        }
                        if(grid[x][y] == 1)
                            return level;
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }
};
