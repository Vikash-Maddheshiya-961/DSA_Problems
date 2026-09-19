class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }

        bool flag = false;
        if(dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0) flag = true;

        int q = 0;
        long long a = dividend > 0 ? dividend : -(long long) dividend;
        long long b = divisor > 0 ? divisor : -(long long) divisor;

        while(a >= b){
            q++;
            a -= b;
        }

        if(flag) return -q;
        return q;
    }
};