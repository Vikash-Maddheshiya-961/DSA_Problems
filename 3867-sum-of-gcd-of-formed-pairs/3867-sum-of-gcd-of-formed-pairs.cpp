class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixGcd;
        int mxi = INT_MIN;
        for(int ele:nums){
            if(mxi < ele) mxi = ele;
            prefixGcd.push_back(__gcd(ele,mxi));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long gcd_sum = 0;
        int lo = 0;
        int hi = n-1;
        while(lo<hi){
            gcd_sum += 0LL + __gcd(prefixGcd[lo],prefixGcd[hi]);
            lo++;
            hi--;
        }
        return gcd_sum;
    }
};