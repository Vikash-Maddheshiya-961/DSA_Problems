class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        int n = nums.size();
        for(int val:nums){
            total_sum += val;
        }

        if(total_sum %2 != 0) return false;
        int target = total_sum/2;
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(int i = 0;i < n;i++){
            for(int j = target;j >= nums[i] ;j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }

        return dp[target];
    }
};