class Solution {
public:
    void solve(vector<vector<int>>& res,vector<int>& candidates,vector<int> ans,int target,int idx){
        if(target == 0){
            res.push_back(ans);
            return;
        }
        if(target < 0) return;
        int prev = -1;
        for(int i=idx;i<candidates.size();i++){
            int curr = candidates[i];
            if(curr!=prev){
                ans.push_back(candidates[i]);
                solve(res,candidates,ans,target-candidates[i],i+1);
                ans.pop_back();
                prev = curr;
            }
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        solve(res,candidates,{},target,0);
        return res;
    }
};