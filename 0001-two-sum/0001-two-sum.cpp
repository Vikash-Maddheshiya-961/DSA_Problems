class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]] = i;
        }
        for(int i=0;i<n;i++){
            int complement = target-nums[i];
            if(mp.find(complement)!=mp.end() && mp[complement]!=i){
                return {i,mp[complement]};
            }
        }
        return {0,0};
    }
};