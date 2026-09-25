class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(m+2,vector<int>(m+2,0));

        for(int i=m; i>=1 ;i--){
            for(int j=1; j<=m; j++){
                if(i > j){
                    dp[i][j] = 0;
                    continue;
                }
                int mini_cost = 1e9;
                for(int k=j; k>=i; k--){
                    int curr_cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini_cost = min(mini_cost,curr_cost);
                }
                dp[i][j] = mini_cost;
            }
        }

        return dp[1][m];
    }
};