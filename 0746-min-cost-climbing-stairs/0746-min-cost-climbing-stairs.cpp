class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> res(n,-1);
        // tabulation / iterative
        // cost[i] = cost[i] + min(cost[i-1],cost[i-2]);
        for(int i=2;i<n;i++){
            cost[i] += min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-2],cost[n-1]);
    }
};