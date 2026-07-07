class Solution {
public:
    int mySqrt(int x) {
        int lo = 1;
        int hi = x;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            long long squr = (long long)mid*mid;
            long long y = (long long)x;
            if(squr == x) return mid;
            else if(squr < x) lo = mid + 1;
            else hi = mid - 1;
        }
        return hi;
    }
};