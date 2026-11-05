class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n , 0);   // Left Smaller Nearest Elements
        vector<int>right(n , 0);   // Right Smaller Nearest Elements
        stack<int>s;

        // Right Smaller
        for(int i = n-1; i >= 0; i--) {
           while(s.size() > 0 && heights[s.top()] >= heights[i]) {
              s.pop();
           }
           right[i] = s.empty() ? n : s.top();
           s.push(i);
        }

        // Make The Stack Emopty Again So That We Can Calculate The Left Smaaller Without Any Error 
        while(!s.empty()) {
           s.pop();
        }

        // Left Smaller
        for(int i = 0; i < n; i++) {
            while(s.size() > 0 && heights[s.top()] >= heights[i]) {
               s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Calculate The Answer
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int currArea = heights[i] * width;
            ans = max(ans , currArea);
        }
        return ans;
    }
};