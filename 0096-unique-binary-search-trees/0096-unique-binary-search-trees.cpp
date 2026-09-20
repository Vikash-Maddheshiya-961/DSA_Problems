class Solution {
public:
    int numTrees(int n) {
        double a = 1;
        double val = 1;
        for(long long i = n+2; i <= 2*n; i++){
            a *= i;
            a /= val;
            val++;
        }
        while(val <= n){
            a /= val;
            val++;
        }
        return (int)a;
    }
};