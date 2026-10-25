class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for(long long val:nums){
            x ^= val;
        }

        long long n = (x & (x - 1)) ^ x;

        long long b1 = 0;
        long long b2 = 0;

        for(long long val:nums){
            if(val & n) b1 ^= val;
            else b2 ^= val;
        }

        return {static_cast<int>(b1),static_cast<int>(b2)};
    }
};