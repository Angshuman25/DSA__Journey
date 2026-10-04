class Solution {
public:
    void merge(vector<pair<int , int>>& arr , int st , int mid , int end , vector<int>& count) {
        vector<pair<int , int>> temp;
        int i = st;
        int j = mid + 1;

        while(i <= mid && j <= end) {
            // If the left element is smaller or equal  , it means all right elements
            // moved so far(from mid + 1 to j - 1) are smaller than arr[i]
            if(arr[i].first <= arr[j].first) {
                count[arr[i].second] += (j - (mid + 1));
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        while(i <= mid) {
            count[arr[i].second] += (j - (mid + 1));
            temp.push_back(arr[i]);
            i++;
        }

        while(j <= end) {
            temp.push_back(arr[j]);
            j++;
        }

        for(int idx = 0; idx < temp.size(); idx++) {
            arr[idx + st] = temp[idx];
        }
    }

    void mergeSort(vector<pair<int , int>>& arr , int st , int end , vector<int>& count) {
        if(st >= end) return;

        int mid = st + (end - st) / 2;
        mergeSort(arr , st , mid , count);
        mergeSort(arr , mid+1 , end , count);
        merge(arr , st , mid , end , count);   
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n , 0);
        vector<pair<int , int>> arr(n);

        // Pair each number with its original index
        for(int i = 0; i < n; i++) {
            arr[i] = {nums[i] , i};
        }

        mergeSort(arr , 0 , n-1 , count);
        return count;
    }
};