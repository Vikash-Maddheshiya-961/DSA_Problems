class Solution {
public:
    void solve(vector<vector<int>>& res,vector<int>& candidates,vector<int> ans,int* target,int idx,int sum){
        if(idx == candidates.size() || sum > *target) return;
        if(sum == *target){
            auto it = find(res.begin(),res.end(),ans);
            if(it == res.end()){
                res.push_back(ans);
            }
            return;
        }
        solve(res,candidates,ans,target,idx+1,sum);
        ans.push_back(candidates[idx]);
        sum = sum + candidates[idx];
        solve(res,candidates,ans,target,idx,sum);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        solve(res,candidates,{},&target,0,0);
        return res;
    }
};