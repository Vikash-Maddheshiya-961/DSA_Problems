class Solution {
public:
    void solve(vector<vector<int>>& subset,vector<int> ans,vector<int> &nums,int idx){
        if(idx == nums.size()){
            subset.push_back(ans);
            return;
        }
        solve(subset,ans,nums,idx+1);
        ans.push_back(nums[idx]);
        solve(subset,ans,nums,idx+1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subset;
        solve(subset,{},nums,0);
        return subset;
    }
};