class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix_sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;

        int cnt = 0;
        for(int val:nums){
            prefix_sum += val;

            int remaining = prefix_sum - k;

            if(mp.find(remaining) != mp.end()){
                cnt += mp[remaining];
            }

            mp[prefix_sum]++;
        }

        return cnt;
    }
};