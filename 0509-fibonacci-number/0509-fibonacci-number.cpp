class Solution {
public:
    vector<int> fibonacci;
    int solve(int n){
        if(n == 0) return fibonacci[0];
        if(n == 1) return fibonacci[1];
        if(fibonacci[n] != -1) return fibonacci[n];
        fibonacci[n] = solve(n-1) + solve(n-2);
        return fibonacci[n];
    }
    int fib(int n) {
        fibonacci.assign(n+2,-1);
        fibonacci[0] = 0;
        fibonacci[1] = 1;
        return solve(n);
    }
};