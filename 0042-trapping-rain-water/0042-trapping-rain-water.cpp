class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // Previous_Greatest_Element Array
        vector<int> PGE(n);
        PGE[0] = -1;
        // next_Greatest_Element Array
        vector<int> NGE(n);
        NGE[n-1] = 0;
        //Filling previous_Element Array
        int max = height[0];
        for(int i=1;i<=n-1;i++){
            PGE[i] = max;
            if(max<height[i]) max = height[i];
        }
        //Filling Next_Element Array
        max = height[n-1];
        for(int i=n-2;i>=0;i--){
            NGE[i] = max;
            if(max<height[i]) max = height[i];
        }
        // Now calculating the amount of trap water
        int water = 0;
        int mini;
        for(int i=1;i<=n-2;i++){
            mini = min(PGE[i],NGE[i]);
            if(height[i] < mini){
                water += mini-height[i];
            }
        }
        return water;
    }
};