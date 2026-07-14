class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prev_max(n,-1);
        vector<int> nxt_max(n,-1);
        int maxi = height[0];
        for(int i=1;i<n;i++){
            prev_max[i] = maxi; 
            if(maxi < height[i]) maxi = height[i];
        }
        maxi = height[n-1];
        for(int i=n-2;i>=0;i--){
            nxt_max[i] = maxi;
            if(maxi < height[i]) maxi = height[i];
        }
        int water = 0;
        for(int i=1;i<=n-2;i++){
            int mini = min(prev_max[i],nxt_max[i]);
            if(height[i] < mini){
                water += mini - height[i];
            }
        }
        return water;
    }
};