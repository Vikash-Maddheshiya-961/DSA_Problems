class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> res(n,-1);
        // tabulation / iterative
        res[n-1] = cost[n-1];
        for(int i=n-2;i>=0;i--){
            int j1 = i+1;
            int j2 = i+2;
            int c1,c2;
            if(j1 >= n) c1 = 0;
            else c1 = res[j1];

            if(j2 >= n) c2 = 0;
            else c2 = res[j2];
            res[i] = cost[i] + min(c1,c2);
        }
        return min(res[0],res[1]);
    }
};