class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, long long int target) {
       long long int m = mat.size();
       long long int n = mat[0].size();

       long long int r = 0 , c = n-1;
       while(r < m && c >= 0) {
           if(target == mat[r][c]) {
               return true;
           } else if(target < mat[r][c]) {
               c--;
           } else { // target > mat[r][c]
               r++;
           }
       } 
       return false;
    }
};