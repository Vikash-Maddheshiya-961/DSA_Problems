class Solution {
public:
    int solve(vector<int>& res,vector<int>& nums,int i){
        int n = nums.size();
        if(i>=n) return 0;
        if(res[i] != -1) return res[i];
        int maxi = nums[i];
        for(int idx = i+2;idx<n;idx++){
            int s = solve(res,nums,idx);
            maxi = max(maxi,nums[i] + s);
        }
        return res[i] = maxi;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        return max(solve(res,nums,0),solve(res,nums,1));
    }
};