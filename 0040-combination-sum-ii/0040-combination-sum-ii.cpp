class Solution {
public:
    void getallCombinations(vector<int> &arr , int idx , int tar , vector<vector<int>>& ans , vector<int>& combin) {
        // Base Case
        if(tar == 0) {
            ans.push_back(combin);
            return;
        }
        // Loop through candidate elements starting from the current index
        for(int i = idx; i < arr.size(); i++) {
            // Pruning 1 : If the element exceeds the remaining target , stop (simce array is sorted)
            if(arr[i] > tar) break;

            // Pruning 2 : Skip duplicate elements at the same recursion depth to avoid duplicate combinations
            if(i > idx && arr[i] == arr[i - 1]) continue;

            // Include the element
            combin.push_back(arr[i]);

            // Move to the next index (i + 1) because each element can only be used once
            getallCombinations(arr , i + 1 , tar - arr[i] , ans , combin);
            
            // Backtrack
            combin.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        
        // 1 : Sorting is mandatory to group duplicates and prune efficiently
        sort(candidates.begin() , candidates.end());

        getallCombinations(candidates , 0 , target , ans , combin);
        return ans;
    }
};