class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        long long rev = 0;
        while(n!=0){
            if(n%10 != 0){
                rev = rev*10 + (n%10);
            }
            n /= 10;
        }
        long long x = 0;
        long long sum = 0;
        while(rev!=0){
            x = x*10 + (rev%10);
            sum += rev%10;
            rev /= 10;
        }
        return x*sum;
    }
};