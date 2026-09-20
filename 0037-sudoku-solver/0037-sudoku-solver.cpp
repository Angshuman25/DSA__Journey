class Solution {
public:
    bool isSafe(vector<vector<char>> &board , int row , int col , char dig) {
        // Horizontal
        for(int j=0; j<9; j++) {
            if(board[row][j] == dig) {
                return false;
            }
        }
        // Vertical
        for(int i=0; i<9; i++) {
            if(board[i][col] == dig) {
                return false;
            }
        }
        // Grid
        int srow = (row/3)*3;
        int scol = (col/3)*3;
        for(int i=srow; i<=srow+2; i++) {
            for(int j=scol; j<=scol+2; j++) {
                if(board[i][j] == dig) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool helper(vector<vector<char>> &board , int row , int col) {
        // Base Case
        if(row == 9) {
            return true;
        }
        int nextRow = row , nextCol = col+1;
        if(nextCol == 9) {
            nextRow = row+1;
            nextCol = 0;
        }
        // When dig already exist in any cell from beginning
        if(board[row][col] != '.') {
           return helper(board , nextRow , nextCol);
        }
        // Place the digit
        for(char dig = '1'; dig<='9'; dig++) {
            if(isSafe(board , row , col , dig)) {
                board[row][col] = dig;
                if(helper(board , nextRow , nextCol)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board , 0 , 0);
    }
};