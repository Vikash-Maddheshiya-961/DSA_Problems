class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        for(int val:nums){
            mp[val]++;
        }

        priority_queue<pi,vector<pi>,greater<pi>> pq;

        for(auto p:mp){
            int val = p.first;
            int freq = p.second;
            pq.push({p.second,p.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            int val = pq.top().second;
            pq.pop();
            ans.push_back(val);
        }

        return ans;
    }
};