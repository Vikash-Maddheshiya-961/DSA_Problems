class Solution {
public:
    void solve(vector<vector<int>>& subset,vector<int> ans,vector<int>& nums,int idx,bool flag){
        if(idx == nums.size()){
            subset.push_back(ans);
            return;
        }
        if(idx == nums.size()-1){
            if(flag == true) solve(subset,ans,nums,idx+1,true);
            ans.push_back(nums[idx]);
            solve(subset,ans,nums,idx+1,true);
            return; 
        }
        int curr = nums[idx];
        int nxt = nums[idx+1];
        if(curr == nxt){
            if(flag == true) solve(subset,ans,nums,idx+1,true);
            ans.push_back(nums[idx]);
            solve(subset,ans,nums,idx+1,false);
        }
        else{
            if(flag == true)solve(subset,ans,nums,idx+1,true);
            ans.push_back(nums[idx]);
            solve(subset,ans,nums,idx+1,true);
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> subset;
        solve(subset,{},nums,0,true);
        return subset;
    }
};