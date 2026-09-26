class Solution {
public:
    int res[31];
    int fibo(int n){
        if(n <= 1) return n;
        if(res[n] != -1) return res[n];
        return res[n] = fibo(n-1) + fibo(n-2);
    }
    int fib(int n) {
        memset(res,-1,sizeof(res));
        return fibo(n);
    }
};