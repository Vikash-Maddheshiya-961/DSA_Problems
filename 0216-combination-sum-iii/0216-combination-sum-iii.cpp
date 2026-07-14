class Solution {
public:
    void solve(vector<vector<int>>& res,vector<int>& nums,vector<int> ans,int target,int k,int idx){
        if(k == 0 && target == 0){
            res.push_back(ans);
            return;
        }
        if(k <= 0 || target < 0) return;
        for(int i=idx; i<nums.size(); i++){
            ans.push_back(nums[i]);
            solve(res,nums,ans,target-nums[i],k-1,i+1);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};\
        vector<vector<int>> res;
        solve(res,nums,{},n,k,0);
        return res;
    }
};