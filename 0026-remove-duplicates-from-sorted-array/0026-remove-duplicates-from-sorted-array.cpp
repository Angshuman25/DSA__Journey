class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        // If the array is empty , there are 0 unique elements
        if(nums.empty()) {
            return 0;
        }

        // This pointer keeps track of where to place the next unique element 
        int uniqueIndex = 0;

        // Loop through the array starting from the second element
        for(int i = 1; i < n; i++) {
            // If we find a new , unique number 
            if(nums[i] != nums[uniqueIndex]) {
                uniqueIndex++; // Move our unique tracker forward
                nums[uniqueIndex] = nums[i]; // Copy the new unique number over
            }
        }
        // The number of unique elements is the index + 1
        return uniqueIndex + 1;
    }
};