class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        int n = nums.size();
        for(int val:nums){
            total_sum += val;
        }

        vector<vector<int>> dp(n+1,vector<int>(2*total_sum + 1,0));

        for(int i = n-1;i>=0;i--){
            for(int j = total_sum; j>=0; j--){
                if(2*j == total_sum) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i+1][j] || dp[i+1][j + nums[i]];
            }
        }

        return dp[0][0];
    }
};