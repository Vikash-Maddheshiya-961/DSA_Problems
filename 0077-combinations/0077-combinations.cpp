class Solution {
public:
    void solve(vector<vector<int>>& res,vector<int> ans,vector<int>& nums,int k,int idx){
        if(k==0){
            res.push_back(ans);
            return;
        }
        if(idx == nums.size()) return;
        for(int i=idx;i<nums.size();i++){
            ans.push_back(nums[i]);
            solve(res,ans,nums,k-1,i+1);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        vector<vector<int>> res;
        solve(res,{},nums,k,0);
        return res;
    }
};