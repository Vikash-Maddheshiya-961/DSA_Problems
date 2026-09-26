class Solution {
public:
    int total_sum;
    int n;
    int res[201][20001];
    bool solve(vector<int>&nums,int idx,int sum){
        if(total_sum == 2*sum) return true;
        if(idx == n) return false;

        if(res[idx][sum] != -1) return res[idx][sum];
        return res[idx][sum] = solve(nums,idx+1,sum) || solve(nums,idx+1,sum+nums[idx]);
    }
    bool canPartition(vector<int>& nums) {
        total_sum = 0;
        n = nums.size();
        for(int val:nums){
            total_sum += val;
        }
        memset(res,-1,sizeof(res));
        return solve(nums,0,0);
    }
};