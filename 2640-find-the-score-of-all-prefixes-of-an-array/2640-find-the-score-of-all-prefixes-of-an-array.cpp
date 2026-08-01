class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);
        // prefix max + conversion array
        int maxi = nums[0];
        nums[0] *= 2;
        ans[0] = nums[0];
        for(int i=1;i<n;i++){
            if(maxi < nums[i]) maxi = nums[i]; 
            nums[i] += maxi;
            ans[i] = ans[i-1] + nums[i];
        }
        return ans;
    }
};