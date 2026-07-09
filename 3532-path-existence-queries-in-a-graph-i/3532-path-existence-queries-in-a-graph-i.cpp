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
        vector<bool> ans(tot_queries);
        for(int i=0;i<tot_queries;i++){
            int node1 = queries[i][0];
            int node2 = queries[i][1];
            if(component[node1] == component[node2]){
                ans[i] = true;
            }
            else{
                ans[i] = false;
            }
        }
        return ans;
    }
};