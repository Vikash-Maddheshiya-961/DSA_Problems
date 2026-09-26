class Solution {
public:
    vector<int> res;
    int solve(vector<int>&nums,int idx,int n){
        if(idx > n){
            return 0;
        }
        if(res[idx] != -1) return res[idx];
        return res[idx] = max(nums[idx]+solve(nums,idx+2,n),solve(nums,idx+1,n));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        res.assign(n,-1);
        int res1 = solve(nums,1,n-1);
        res.assign(n,-1);
        int res2 = solve(nums,0,n-2);
        return max(res1,res2);
    }
};