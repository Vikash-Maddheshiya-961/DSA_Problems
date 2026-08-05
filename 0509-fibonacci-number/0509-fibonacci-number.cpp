class Solution {
public:
    int fib(int n) {
        vector<int> fibo(n+1,-1);
        for(int i=0;i<=n;i++){
            if(i <= 1) fibo[i] = i;
            else fibo[i] = fibo[i-1] + fibo[i-2]; 
        }
        return fibo[n];
    }
};