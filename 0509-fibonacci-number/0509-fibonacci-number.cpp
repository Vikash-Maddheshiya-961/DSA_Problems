class Solution {
public:
    vector<int> res;
    int fibo(int n){
        if(n<=1) return n;
        if(res[n] != -1) return res[n];
        return res[n] = fibo(n-1) + fibo(n-2);
    }
    int fib(int n) {
        res.assign(n+1,-1);
        return fibo(n);
    }
};