class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
      int n = A.size();

      if(n == 1) return A[0];

      int st=0, end=n-1;
      while(st <= end) {
        int mid = st+(end-st)/2;

        if(mid == 0 && A[0] != A[1]) return A[mid];  // Edge Case
        if(mid == n-1 && A[n-1] != A[n-2]) return A[mid]; // Edge Case

        if(A[mid-1] != A[mid] && A[mid] != A[mid+1]) return A[mid]; //In Case of mid == ans

        if(mid % 2 == 0) { // Even
           if(A[mid-1] == A[mid]) { // Left Search
            end = mid-1;
           } else { // Right Search
            st = mid+1;
           }
        } else { // Odd
           if(A[mid-1] == A[mid]) { // Right Search
            st = mid+1;
           } else { // Left Search
            end = mid-1;
           }
        }
      }
      return -1;
    }
};