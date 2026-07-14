class Solution {
public:
    void solve(vector<vector<int>>& res,vector<int>& candidates,vector<int> ans,int target,int idx){
        if(target == 0){
            res.push_back(ans);
            return;
        }
        if(target < 0) return;
        for(int i=idx;i<candidates.size();i++){
            ans.push_back(candidates[i]);
            solve(res,candidates,ans,target-candidates[i],i);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        solve(res,candidates,{},target,0);
        return res;
    }
};