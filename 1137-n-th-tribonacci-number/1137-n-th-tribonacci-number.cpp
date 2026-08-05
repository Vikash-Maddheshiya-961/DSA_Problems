class Solution {
public:
    vector<int> res;
    int solve(int n){
        if(n == 0) return 0;
        if(n==1 || n==2) return 1;
        if(res[n]!=-1) return res[n];
        return res[n] = solve(n-1) + solve(n-2) + solve(n-3);
    }
    int tribonacci(int n) {
        res.assign(n+1,-1);
        return solve(n);
        // recursive approach
    }
};