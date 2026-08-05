class Solution {
public:
    int tribonacci(int n) {
        // tabulation / iterative approach (bottom up approach)
        int res[n+1];
        for(int i=0;i<=n;i++){
            if(i == 0) res[i] = 0;
            else if(i == 1 || i == 2) res[i] = 1;
            else res[i] = res[i-1] + res[i-2] + res[i-3];
        }
        return res[n];
    }
};