class Solution {
public:
    bool judgeSquareSum(int c) {
        long long k = (long long)c;
        long long i = sqrt(k);
        for(long long b=0;b<=i;b++){
            long long a = sqrt(k - (b*b));
            if(((a*a) + (b*b)) == k){
                return true;
            }
        }
        return false;
    }
};