class Solution {
public:
    int res[31];
    int fibo(int n){
        if(n <= 1) return n;
        if(n == 2) return 1;

        if(res[n]!=-1) return res[n];
        if(n%2 != 0){
            int a = fibo(n/2);
            int b = fibo(n/2 + 1);
            return res[n] = a*a + b*b;
        }

        int a = fibo(n/2 + 1);
        int b = fibo(n/2 - 1);

        return res[n] = a*a - b*b;
    }
    int fib(int n) {
        if(n <= 1) return n;
        memset(res,-1,sizeof(res));
        return fibo(n);
    }
};