class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxarea = 0;
        int l=0,r=n-1;
        while(l<r){
            int min_height = height[l]<height[r]?height[l]:height[r];
            int dis = r-l;
            int area = (min_height)*dis;
            if(area>maxarea) maxarea = area;
            if(height[l]<height[r]) l++;
            else r--;
        }
        return maxarea;
    }
};