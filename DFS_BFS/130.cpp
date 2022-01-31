#include <iostream>
#include <sec_api/stdio_s.h>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> position{-1, 0, 1, 0, -1};

public:
  void dfs(vector<vector<char>> &board, vector<vector<int>> &flag, int m, int n,
           int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] == 'X' || flag[r][c] == 1) {
      return;
    }
    flag[r][c] = 1;
    for (int i = 0; i < 4; ++i) {
      dfs(board, flag, m, n, r + position[i], c + position[i + 1]);
    }
  }
  void solve(vector<vector<char>> &board) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> flag(m, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dfs(board, flag, m, n, 0, i);
      dfs(board, flag, m, n, m - 1, i);
    }
    for (int i = 0; i < m; ++i) {
      dfs(board, flag, m, n, i, 0);
      dfs(board, flag, m, n, i, n - 1);
    }
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (board[i][j] == 'O' && flag[i][j] == 0) {
          board[i][j] = 'X';
        }
      }
    }
  }
};