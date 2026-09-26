class Solution {
public:
    int n;
    int res[1001];
    int solve(vector<int>&cost,int idx){
        if(idx >= n) return 0;
        if(res[idx]!=-1) return res[idx];

        int step1 = solve(cost,idx+1);
        int step2 = solve(cost,idx+2);

        return res[idx] = cost[idx] + min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        memset(res,-1,sizeof(res));
        return min(solve(cost,0),solve(cost,1));
    }
};