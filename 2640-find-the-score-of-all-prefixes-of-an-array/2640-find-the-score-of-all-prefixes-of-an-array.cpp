class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        // prefix max + conversion array
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(maxi < nums[i]) maxi = nums[i]; 
            nums[i] += maxi;
        }
        // now prefix sum
        vector<long long> ans(n);
        ans[0] = nums[0];
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1] + nums[i];
        }
        return ans;
    }
};