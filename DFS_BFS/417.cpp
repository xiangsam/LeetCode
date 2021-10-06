#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> direction = { -1, 0, 1, 0, -1 };
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& reach, int r, int c)
    {
        if (reach[r][c])
            return;
        reach[r][c] = true;
        for (int i = 0; i < 4; ++i) {
            int x = r + direction[i];
            int y = c + direction[i + 1];
            if (x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size() && heights[x][y] >= heights[r][c])
                dfs(heights, reach, x, y);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        if (heights.size() == 0 || heights[0].size() == 0)
            return {};
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> reach_pacific(m, vector<bool>(n, false));
        vector<vector<bool>> reach_atlantic(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            dfs(heights, reach_pacific, i, 0);
            dfs(heights, reach_atlantic, i, n - 1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(heights, reach_pacific, 0, i);
            dfs(heights, reach_atlantic, m - 1, i);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (reach_atlantic[i][j] && reach_pacific[i][j]) {
                    ans.push_back({ i, j });
                }
            }
        }
        return ans;
    }
};
