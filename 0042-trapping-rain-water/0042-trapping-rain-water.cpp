class Solution {
public:
    int min(int a,int b){
        if(a<b) return a;
        return b;
    }
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
        int w = 0;
        int m;
        for(int i=1;i<=n-2;i++){
            m = min(PGE[i],NGE[i]);
            if(height[i] < m){
                w += m-height[i];
            }
        }
        return w;
    }
};