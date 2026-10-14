class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Step 1 : Create a checklist filled with 0s (size n + 1)
        vector<int> checklist(n + 1 , 0);

        // Step 2 : Mark every number that were never marked
        for(int i = 0; i < n; i++) {
            int current_number = nums[i];
            checklist[current_number] = 1;
        }
   
        // Step 3 : Collect numbers that were never marked
        vector<int>result;
        for(int i = 1; i <= n; i++) {
            if(checklist[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};