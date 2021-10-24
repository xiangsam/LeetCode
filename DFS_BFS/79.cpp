#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<int> direction = {-1,0,1,0,-1};
public:
    void backtrace(vector<vector<char>>&board, string& word,bool& finded, int r, int c, int pos)
    {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if(board[r][c] == '#' || finded) return;
        if(board[r][c] != word[pos]) return;
        if(pos == word.size()-1){
            finded = true;
            return;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        for(int i = 0; i < 4; ++i){
            backtrace(board, word, finded, r + direction[i], c + direction[i+1], pos+1);
        }
        board[r][c] = temp;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool finded = false;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                backtrace(board, word, finded, i,j,0);
            }
        }
        return finded;
    }
};
