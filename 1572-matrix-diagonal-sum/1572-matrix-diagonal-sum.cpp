class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
       int n = mat.size();
       int total_sum = 0;

       for(int i=0; i<n; i++) {
          total_sum += mat[i][i];
          total_sum += mat[i][n-1-i];
       }

       if(n % 2 != 0) {
          total_sum -= mat[n / 2][n / 2];
       }
       return total_sum;
    }
};