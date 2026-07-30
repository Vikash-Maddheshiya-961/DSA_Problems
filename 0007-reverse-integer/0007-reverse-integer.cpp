class Solution {
public:
    int reverse(int x) {
        long long num = (long long) x;
        int neg = 0;
        if(x < 0){
            neg = 1;
            if(-1*num > INT_MAX) return 0;
            num = abs(num);
        }
        long long int rev = 0;
        while(num!=0){
            rev = rev * 10 + num %10;
            if(rev > INT_MAX) return 0;
            num /= 10;
        }
        if(neg == 1){
            return -1*rev;
        }
        return rev;
    }
};