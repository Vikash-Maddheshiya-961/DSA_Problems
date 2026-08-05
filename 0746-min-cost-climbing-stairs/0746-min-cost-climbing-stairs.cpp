class Solution {
public:
    int solve(vector<int>& res,vector<int>& cost,int i){
        if(i >= cost.size()) return 0;
        if(res[i] != -1) return res[i];
        return res[i] = cost[i] + min(solve(res,cost,i+1),solve(res,cost,i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> res(n,-1);
        return min(solve(res,cost,0), solve(res,cost,1));
    }
};