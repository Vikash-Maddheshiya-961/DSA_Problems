class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int val:nums){
            mp[val]++;
        }

        vector<int> ans;

        for(auto& p:mp){
            if(p.second == 1) ans.push_back(p.first);
        }

        return ans;
    }
};