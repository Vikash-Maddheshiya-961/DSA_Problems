class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i > j){
                    dp[i][j] = 0;
                    continue;
                }

                int max_coin = INT_MIN;
                for(int k=i;k<=j;k++){

                    int curr_coin = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    max_coin = max(max_coin,curr_coin);
                }

                dp[i][j] = max_coin;
            }
        }
        return dp[1][n];
    }
};