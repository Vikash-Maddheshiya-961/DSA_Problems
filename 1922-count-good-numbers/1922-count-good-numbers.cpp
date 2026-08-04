class Solution {
public:
    long long mod = 1e9 + 7;
    long long power(long long a,long long b){
        if(b == 0) return 1;
        long long x = power(a,b/2) % mod;
        if(b % 2 !=0) return (x * x * a + mod) % mod;
        return (x * x + mod) % mod;
    }
    int countGoodNumbers(long long n) {
        long long e,o;
        if(n % 2 != 0){
            e = n/2 + 1;
        }
        else{
            e = n/2;
        }
        o = n/2;
        return ((power(5,e) % mod) * (power(4,o) % mod) + mod) % mod;
    }
};