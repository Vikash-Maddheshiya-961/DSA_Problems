class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;

        for(int A=1;A<=amount;A++){
            for(int i=0;i<n;i++){
                if(coins[i] <= A){
                    dp[A] = min(dp[A],1 + dp[A-coins[i]]);
                }
            }
        }

        if(dp[amount] == amount+1) return -1;
        return dp[amount];
    }
};