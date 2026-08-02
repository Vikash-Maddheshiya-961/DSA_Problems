class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] >= target) return 1;
        }

        vector<int> prefix(n);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        // now traversing for k --> subarray;
        int lo = 2;
        int hi = n;
        int ans = 0;
        while(lo <= hi){
            int k = lo + (hi - lo) / 2;
            if(prefix[k-1] >= target){
                ans = k;
                hi = k - 1;
                continue;
            }
            int i=1;
            int j=k;
            int prev = ans;
            while(j<n){
                int sum = prefix[j] - prefix[i-1];
                if(sum >= target){
                    ans = k;
                    hi = k-1;
                    break;
                }
                i++;
                j++;
            }
            if(prev!=ans) continue;
            lo = k + 1;
        }
        return ans;
    }
};