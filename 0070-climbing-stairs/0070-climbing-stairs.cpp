class Solution {
public:
    vector<int> res;
    int solve(int n){
        if(n == 1) return res[1];
        if(n == 2) return res[2];
        if(res[n] != -1) return res[n];
        res[n] = solve(n-1) + solve(n-2);
        return res[n];
    }
    int climbStairs(int n) {
        res.assign(n+2,-1);
        res[1] = 1;
        res[2] = 2;
        return solve(n);
    }
};