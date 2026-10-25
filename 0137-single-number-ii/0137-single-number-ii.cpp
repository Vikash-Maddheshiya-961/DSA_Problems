class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int val:nums){
            mp[val]++;
        }

        for(auto p:mp){
            if(p.second == 1) return p.first;
        }

        return -1;
    }
};