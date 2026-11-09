class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n , vector<int>(n));
        int sRow = 0 , eRow = n -1 , sCol = 0 , eCol = n -1;
        int num = 1;

        while(sRow <= eRow && sCol <= eCol) {
            // Top
            for(int j = sCol; j <= eCol; j++) {
                mat[sRow][j] = num++;
            }

            // Right
            for(int i = sRow + 1; i <= eRow; i++) {
                mat[i][eCol] = num++;
            }

            // Bottom
            for(int j = eCol - 1; j >= sCol; j--) {
                if(sRow == eRow)  break;
                mat[eRow][j] = num++;
            }

            // Left
            for(int i = eRow - 1; i >= sRow + 1; i--) {
                if(sCol == eCol)  break;
                mat[i][sCol] = num++;
            }
            sRow++; eRow--; sCol++; eCol--;
        }
        return mat;
    }
};