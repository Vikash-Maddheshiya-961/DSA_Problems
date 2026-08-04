class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double a = myPow(x,n/2);
        if(n < 0 && n%2 == 0){
            return a * a;
        }
        if(n < 0 && n%2 !=0 ){
            return a * a * (1 / x);
        }
        if(n > 0 && n%2 == 0){
            return a * a;
        }
        return a * a * x;
    }
};