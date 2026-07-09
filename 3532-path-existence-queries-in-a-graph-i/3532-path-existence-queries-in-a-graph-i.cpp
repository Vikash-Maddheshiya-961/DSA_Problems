class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int tot_queries = queries.size();
        vector<int> component(n,0);
        for(int i=1;i<n;i++){
            int diff = abs(nums[i]-nums[i-1]);
            if(diff <= maxDiff){
                component[i] = component[i-1];
            }else{
                component[i] = i;
            }
        }
        vector<bool> ans;
        for(int i=0;i<tot_queries;i++){
            ans.push_back(component[queries[i][0]] == component[queries[i][1]]);
        }
        return ans;
    }
};