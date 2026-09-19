class Solution {
public:
    bool isSafe(vector<string> &board , int row , int col , int n) {
        // Horizontal Check
        for(int j=0; j<n; j++) {
            if(board[row][j] == 'Q') {
                return false;
            }
        }

        // Vertical Check
        for(int i=0; i<n; i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }

        // Left Diagonal Check(moving up and left)
        for(int i=row , j=col; i>=0 && j>=0; i-- , j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }

        // Right Diagonal Check(moving up and right)
        for(int i=row , j=col; i>=0 && j<n; i-- , j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void nQueens(vector<string> &board , int row , int n , int &count) {
        // Base Case: all queens are successfully placed , increament count
        if(row == n) {
           count++;
           return;
        }
        // Try placing a queen in each column of the current row
        for(int j=0; j<n; j++) {
            if(isSafe(board , row , j , n)) {
                board[row][j] = 'Q';
                nQueens(board , row+1 , n , count);
                board[row][j] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> board(n , string(n , '.'));
        int count = 0;

        nQueens(board , 0 , n , count);
        return count;
    }
};