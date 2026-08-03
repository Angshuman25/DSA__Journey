class Solution {
public:
    int maxArea(vector<int>& height) {
    int maxWater = 0;
    int n = height.size();
    int lp=0, rp= n-1;

    while(lp < rp) {
        int wd = rp-lp;
        int ht = min(height[lp] , height[rp]);
        int currWater = wd * ht;
        maxWater = max(maxWater , currWater);

        height[lp] < height[rp] ? lp++ : rp--;
    } 
    return maxWater;  
    }
};