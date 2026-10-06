class Solution {
public:
    // Pass the pre-allocated temp vector by reference
    long long merge(vector<int>& arr ,  vector<int>& temp , int st , int mid , int end) {
        int i = st;
        int j = mid + 1;
        int k = st;  // Track position in the shared temp array
        long long mvCount = 0;

        while(i <= mid && j <= end) {
            if(arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                // Elements remaining in the left subarray form global inversions
                mvCount += (mid - i + 1);
            }
        }
        while(i <= mid) {
            temp[k++] = arr[i++];
        }
        while(j <= end) {
            temp[k++] = arr[j++];
        }
        // Copy back only the section that was just merged
        for(int idx = st; idx <= end; idx++) {
            arr[idx] = temp[idx];
        }
        
        return mvCount;
    }

    // Pass temp vector down through the recursion
    long long mergeSort(vector<int>& arr , vector<int>& temp , int st , int end) {
        if(st >= end) return 0;

        int mid = st + (end - st) / 2;
        long long leftInvCount = mergeSort(arr , temp , st ,  mid);
        long long rightInvCount = mergeSort(arr , temp , mid + 1 , end);
        long long invCount = merge(arr , temp , st , mid , end);

        return leftInvCount + rightInvCount + invCount;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();

        // Count Local Inversions : adjacent elements only
        long long localInversions = 0;
        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                localInversions++;
            }
        }
        
        // Allocate memory once here to prevent runtime overhead
        vector<int> temp(n);
        // Count Global Inversions uses merge sort logic
        long long globalInversions = mergeSort(nums , temp , 0 , n - 1);
        // The Question asks if global inversions equal local inversions
        return globalInversions == localInversions;
    }
};