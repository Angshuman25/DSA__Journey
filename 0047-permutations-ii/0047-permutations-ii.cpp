class Solution {
public:
    void getPerms(vector<int> &nums , int idx , vector<vector<int>> &ans) {
        if(idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for(int i = idx; i < nums.size(); i++) {
            // Only proceed if nums[i] has NOT been used at this position yet
            if(used.find(nums[i]) == used.end()) {
                used.insert(nums[i]);

                swap(nums[idx] , nums[i]);
                getPerms(nums , idx + 1 , ans);
                swap(nums[idx] , nums[i]);
            }
        } 
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> ans;
        getPerms(nums , 0 , ans);
        return ans;
    }
};