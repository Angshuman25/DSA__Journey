class Solution {
public:
    // The Exact Logic to check if a digit is valid in its row , column , and 3x3 box
    bool isSafe(vector<vector<char>>& board , int row , int col , int dig) {
        // Horizontal Check
        for(int j=0; j<9; j++) {
            if(board[row][j] == dig) {
                return false;
            }
        }
        // Vertical Check
        for(int i=0; i<9; i++) {
            if(board[i][col] == dig) {
                return false;
            }
        }
        // 3x3 grid check
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;
        for(int i=srow; i<=srow+2; i++) {
            for(int j=scol; j<=scol+2; j++) {
                if(board[i][j] == dig) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                // Only validate cells that already contain a digit
                if(board[r][c] != '.') {
                    char dig = board[r][c];

                    // Temporarily clear the cell so it doesn't match against itself
                    board[r][c] = '.';

                    // Run my validation check
                    if(!isSafe(board , r , c , dig))
                        return false;

                    // Restore the digit back to the board
                    board[r][c] = dig;
                }
            }
        }
        return true;
    }
};