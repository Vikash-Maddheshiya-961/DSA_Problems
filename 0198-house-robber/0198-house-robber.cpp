class Solution {
public:
    vector<int> res;
    int solve(vector<int>& nums,int i){
        int n = nums.size();
        if(i == n-1) return nums[i];
        if(i == n-2) return max(nums[i],nums[i+1]);
        if(res[i] != -1) return res[i];
        
        return res[i] = max(nums[i] + solve(nums,i+2),solve(nums,i+1));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        res.assign(n,-1);
        return solve(nums,0);
    }
};