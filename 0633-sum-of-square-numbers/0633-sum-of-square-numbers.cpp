class Solution {
public:
    long long sroot(long long x){
        long long lo = 1;
        long long hi = x;
        while(lo <= hi){
            long long mid = lo + (hi-lo)/2;
            if((mid*mid) == x){
                return mid;
            }
            else if((mid*mid) < x){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;;
            }
        }
        return hi;
    }
    long long power(long long a,int b){
        return a*a;
    }
    bool judgeSquareSum(int c) {
        long long k = (long long)c;
        long long i = sroot(c);
        for(int b=0;b<=i;b++){
            long long a = sroot(k - power(b,2));
            if((power(a,2) + power(b,2)) == k){
                return true;
            }
        }
        return false;
    }
};