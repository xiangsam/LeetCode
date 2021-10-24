#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void backTrace(vector<vector<string>>& ans,vector<string>& board, vector<bool>& usedColumn, vector<bool>& usedLDig, vector<bool>& usedRDig, int n, int row){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int c = 0; c < n; ++c){
            if(usedColumn[c] || usedLDig[row-c+n-1] || usedRDig[row+c])
                continue;
            board[row][c] = 'Q';
            usedColumn[c] = usedLDig[row-c+n-1] = usedRDig[row+c] = true;
            backTrace(ans, board, usedColumn, usedLDig, usedRDig, n, row+1);
            board[row][c] = '.';
            usedColumn[c] = usedLDig[row-c+n-1] = usedRDig[row+c] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> usedColumn(n, false);
        vector<bool> usedLDig(2*n-1, false);
        vector<bool> usedRDig(2*n-1, false);
        backTrace(ans,board, usedColumn, usedLDig, usedRDig, n, 0);
        return ans; 
    }
};
