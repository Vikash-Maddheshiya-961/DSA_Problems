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

        long long a = dividend > 0 ? dividend : -(long long) dividend;
        long long b = divisor > 0 ? divisor : -(long long) divisor;

        long long q = 0;
        while(a >= b){
            a -= b;
            q++;
        }

        if(flag == true) return -q;

        return q;
    }
};