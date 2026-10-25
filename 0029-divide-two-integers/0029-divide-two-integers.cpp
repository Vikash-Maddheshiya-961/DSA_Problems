class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        if(divisor == dividend) return 1;
        if(divisor == -1){
            if(dividend == INT_MIN) return INT_MAX;
            return -(dividend);
        }

        bool flag = false;

        if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) flag = true;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long quotient = 0;
        while(a >= b){
            long long cnt = 0;
            while(a >= (b << (cnt+1))){
                cnt++;
            }

            quotient += (1 << cnt);

            a = a - (b << cnt);
        }

        if(flag == true) return -quotient;

        return quotient;
    }
};