class Solution {
public:
    int res[5001][301];
    int solve(int A,vector<int>&coins,int idx){
        if(A == 0) return 1;
        if(idx == -1) return 0;

        if(res[A][idx] != -1) return res[A][idx];
        if(coins[idx] <= A){
            return res[A][idx] = solve(A-coins[idx],coins,idx) + solve(A,coins,idx-1);
        }

        return res[A][idx] = solve(A,coins,idx-1);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        memset(res,-1,sizeof(res));
        return solve(amount,coins,n-1);
    }
};