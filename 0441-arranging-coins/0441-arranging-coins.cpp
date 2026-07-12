class Solution {
public:
    int arrangeCoins(int n) {
        long long  ans;
        long long lo = 1;
        long long hi = (long long)n;
        while(lo <= hi){
            long long mid = lo + (hi - lo) / 2;
            long long temp = mid*(mid+1) / 2;
            if(temp == n) return mid;
            else if(temp <= n){
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return (int)ans;
    }
};