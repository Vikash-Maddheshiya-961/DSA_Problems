class Solution {
public:
    int solve(vector<int>& res,vector<int>& cost,int i){
        if(i >= cost.size()) return 0;
        if(res[i] != -1) return res[i];
        int c1 = cost[i] + solve(res,cost,i+1);
        int c2 = cost[i] + solve(res,cost,i+2);
        res[i] = min(c1,c2);
        return res[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> res(n,-1);
        return min(solve(res,cost,0), solve(res,cost,1));
    }
};