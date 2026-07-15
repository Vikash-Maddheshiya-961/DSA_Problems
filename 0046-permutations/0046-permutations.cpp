class Solution {
public:
    void solve(vector<vector<int>>& res,vector<int>ans,vector<int> nums){
        if(nums.size() == 0){
            res.push_back(ans);
            return;
        }
        vector<int> temp;
        for(int i=0;i<nums.size();i++){
            ans.push_back(nums[i]);
            for(int j=0;j<nums.size();j++){
                if(j==i) continue;
                else temp.push_back(nums[j]);
            }
            solve(res,ans,temp);
            ans.pop_back();
            while(temp.size()!=0){
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(res,{},nums);
        return res;
    }
};