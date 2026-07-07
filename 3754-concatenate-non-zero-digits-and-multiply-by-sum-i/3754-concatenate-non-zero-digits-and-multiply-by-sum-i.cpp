class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0) return 0;
        long long x = 0;
        long long sum = 0;
        int z = 1;
        while(n!=0){
            if((n%10) == 0){
                n/=10;
                continue;
            }
            x = (n%10)*z + x;
            z*=10;
            sum += n%10;
            n /= 10;
        }
        return x*sum;
    }
};