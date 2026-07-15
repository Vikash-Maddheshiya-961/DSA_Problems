class Solution {
public:
    void solve(vector<vector<int>>& res,vector<int>ans,vector<int> &nums,vector<int> used){
        if(ans.size() == nums.size()){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i] == 1) continue;
            ans.push_back(nums[i]);
            used[i] = 1;
            solve(res,ans,nums,used);
            ans.pop_back();
            used[i] = 0;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> used(nums.size(),0);
        solve(res,{},nums,used);
        return res;
    }
};