class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<int> dp(n,1);
        vector<int> hash(n);
        int max_len = 1;
        int max_idx = 0;
        for(int i=1;i<n;i++){
            hash[i] = i;
            for(int prev = 0;prev<i;prev++){
                if(nums[i]%nums[prev] == 0){
                    if(dp[i] < dp[prev] + 1){
                        dp[i] = dp[prev] + 1;
                        hash[i] = prev;
                    }
                }
            }
            if(max_len < dp[i]){
                max_len = dp[i];
                max_idx = i;
            }
        }
        vector<int> ans;
        int i = max_idx;
        ans.push_back(nums[i]);
        while(hash[i]!=i){
            int curr = hash[i];
            ans.push_back(nums[curr]);
            i = curr;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};