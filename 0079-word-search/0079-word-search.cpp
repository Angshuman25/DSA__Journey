class Solution {
private:
    // Backtracking Helper
    bool dfs(vector<vector<char>>& board , int r , int c , string& word , int index) {

        // Step 1 : Base Case - If the entire word is matched , we win
        if(index == word.length()) {
            return true;
        }

        // Step 2 : Safety Check - Out of bounds OR Wrong character OR already visited ('#')
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        // Step 3 : Make Move - Mark Current Cell as visited
        char originalChar = board[r][c];
        board[r][c] = '#';

       // Step 4 : Recursive Calls - Try all 4 directions explicitly
       bool found = dfs(board , r + 1 , c , word , index + 1) || // Down 
                    dfs(board , r , c + 1 , word , index + 1) || // Right
                    dfs(board , r - 1 , c , word , index + 1) || // Up
                    dfs(board , r , c - 1 , word , index + 1);   // Left
        
       // Step 5 : Backtracks - Restore the charcter for other paths
       board[r][c] = originalChar;

       return found;
    }
public:
    bool exist(vector<vector<char>>& board , string& word) {
       int rows = board.size();
       int cols = board[0].size();

       // Scan the entire board to find the starting letter
       for(int r = 0; r < rows; r++) {
          for(int c = 0; c < cols; c++) {
             // If dfs returns true from this starting cell , the word exists
             if(dfs(board , r , c , word , 0)) {
                return true;
             }
          }
       }
       return false;
    }
};