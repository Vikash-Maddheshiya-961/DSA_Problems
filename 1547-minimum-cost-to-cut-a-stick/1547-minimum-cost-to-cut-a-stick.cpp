class Solution {
public:
    int solve(vector<int> &cuts,int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int mini_cost = 1e9;
        for(int k=i;k<=j;k++){
            int curr_cost = cuts[j+1] - cuts[i-1] + solve(cuts,i,k-1,dp) + solve(cuts,k+1,j,dp);
            mini_cost = min(mini_cost,curr_cost);
        }

        return dp[i][j] = mini_cost;
    }
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
        return solve(cuts,1,m,dp);
    }
};