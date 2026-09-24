class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& v1,vector<int>& v2){
            if(v1[0] == v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0];
        });

        // Longest Increasing Subsequence
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            int h = envelopes[i][1];
            if(h > ans.back()) ans.push_back(h);
            else {
                int index = lower_bound(ans.begin(),ans.end(),h) - ans.begin();
                ans[index] = h;
            }
        }
        return ans.size();
    }
};