/*
 * @Author: Samrito
 * @Date: 2022-04-12 20:25:23
 * @LastEditors: Samrito
 * @LastEditTime: 2022-04-12 21:22:32
 */
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) { solver(board, 0, 0); }
  //判断是否可以解决
  bool solver(vector<vector<char>> &board, int row, int col) {
    if (row == 9) {
      return true;
    }
    if (col == 9) {
      return solver(board, row + 1, 0);
    }
    if (board[row][col] != '.')
      return solver(board, row, col + 1);
    for (char c = '1'; c <= '9'; ++c) {
      if (!isValid(board, row, col, c))
        continue;
      board[row][col] = c;
      if (solver(board, row, col))
        return true;
      board[row][col] = '.';
    }
    return false;
  }
  // 用来判断是否可以在(row, col)上填入字符c
  bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; ++i) {
      if (board[i][col] == c)
        return false;
    }
    for (int j = 0; j < 9; ++j) {
      if (board[row][j] == c)
        return false;
    }
    int little_board_x = row / 3;
    int little_board_y = col / 3;
    for (int i = 3 * little_board_x; i < 3 * (little_board_x + 1); ++i) {
      for (int j = 3 * little_board_y; j < 3 * (little_board_y + 1); ++j) {
        if (board[i][j] == c)
          return false;
      }
    }
    return true;
  }
};