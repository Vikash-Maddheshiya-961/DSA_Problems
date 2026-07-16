class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int lo = 0;
        int hi = n-1;
        int max_area = INT_MIN;
        while(lo<hi){
            int curr_area = (hi-lo)*min(height[lo],height[hi]);
            if(max_area < curr_area) max_area = curr_area;
            if(height[lo] < height[hi]) lo++;
            else hi--;
        }
        return max_area;
    }
};