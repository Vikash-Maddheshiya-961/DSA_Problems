class Solution {
public:
    int fib_mem(int n,vector<int>& m){
        int result;
        if(m[n] == -1){
            if(n<=1) result = n;
            else result = fib_mem(n-1,m) + fib_mem(n-2,m);
            m[n]=result;
        }
        return m[n];
    }
    int fib(int n) {
        vector<int> m(n+1,-1);
        return fib_mem(n,m);
    }
};