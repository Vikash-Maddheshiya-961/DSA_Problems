class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int maxi = INT_MIN;
        while(i<j){
            int curr = (j-i)*min(height[i],height[j]);
            maxi = max(maxi,curr);
            if(height[i] <= height[j]) i++;
            else j--;
        }
        return maxi;
    }
};