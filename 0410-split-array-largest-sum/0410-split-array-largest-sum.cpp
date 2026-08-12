class Solution {
public:
    int splitArray(vector<int>&nums , int k) {
        int low = 0;
        int high = 0;
        int n = nums.size();
        // Find the largest single number and the total sum
        for(int i = 0; i < n; i++) {
            if(nums[i] > low) {
                low = nums[i];
            } 
            high += nums[i];
        }

        int answer = high;

        // Binary Search
        while(low <= high) {
            int mid = low + (high - low) / 2;  // Our guess for the max sum

            int pieces = 1 ;  // Count how many pieces we spilt the array into
            int curr_Sum = 0;

            // Try to spilt the array using'mid' as the limit
            for(int i = 0; i < n; i++) {
                // It fits in the current group
                if(curr_Sum + nums[i] <= mid) {
                    curr_Sum += nums[i];
                // This number makes the group too big! Start a new group
                } else {
                    pieces++;
                    curr_Sum = nums[i];
                }
            }
            // Check if our guess worked
            if(pieces <= k) {
                answer = mid; // This limit works! Save it
                high = mid-1; // Try to find a smaller working limit
            } else {
                low = mid+1; // Too many pieces! The limit is too small
            }
        }
        return answer;
    }
};