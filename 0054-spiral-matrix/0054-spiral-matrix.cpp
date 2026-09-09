class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int sRow = 0 , eRow = m-1 , sCol = 0 , eCol = n-1;

        vector<int> ans;

        while(sRow <= eRow && sCol <= eCol) {
            // top
            for(int j = sCol; j <= eCol; j++) {
                ans.push_back(mat[sRow][j]);
            }
            // right
            for(int i = sRow+1; i <= eRow; i++) {
                ans.push_back(mat[i][eCol]);
            }
            // bottom
            for(int j = eCol-1; j >= sCol; j--) {
                if(sRow == eRow) {
                    break;
                }
                ans.push_back(mat[eRow][j]);
            }
            // left
            for(int i = eRow-1; i >= sRow+1; i--) {
                if(sCol == eCol) {
                    break;
                }
                ans.push_back(mat[i][sCol]);
            }
            sRow++;; eRow--; sCol++; eCol--;
        }
        return ans;
    }
};