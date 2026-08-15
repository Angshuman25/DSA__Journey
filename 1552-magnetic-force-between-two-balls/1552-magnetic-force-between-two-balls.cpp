class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
       sort(position.begin() , position.end());
       int n = position.size();
       // Find The Range of Searching
       int low = 1;
       int high = position.back() - position.front(); 
       int ans = 0;

       // Binary Search
       while(low <= high) {
           int mid = low + (high - low) / 2;

           int ballsPlaced = 1;
           int lastPos = position[0];

           for(int i=1; i<n; i++) {
               if(position[i] - lastPos >= mid) {
                   ballsPlaced++;
                   lastPos = position[i];
               }
           }

           if(ballsPlaced >= m) { // Mid is possible ans
              ans = mid;
              low = mid+1; // Right Search
           } else { // Mid is not possible ans
              high = mid-1; // Left Search
           }
       }
       return ans;
    }
};