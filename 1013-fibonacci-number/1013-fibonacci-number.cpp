class Solution {
public:
      int fib(int n){
        if(n<=1) return n;
        vector<int> m(n+1,-1);
        m[0] = 0;
        m[1] = 1;
        for(int i=2;i<=n;i++){
            m[i] = m[i-1]+m[i-2];
        }
        return m[n];
      }
};