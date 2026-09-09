class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mp;
        for(int val:nums){
            mp[val]++;
        }

        int n = nums.size() / 2;
        for(auto p:mp){
            if(p.second > n) return p.first;
        }

        return -1;
    }
};