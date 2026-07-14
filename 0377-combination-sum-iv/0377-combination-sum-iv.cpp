class Solution {
public:
    int solve(vector<int>& res,vector<int>& nums,int target){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(res[target]!=-1) return res[target];
        int count = 0;
        for(int i=0;i<nums.size();i++){
            count +=solve(res,nums,target - nums[i]);
        }
        return res[target] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> res(target+1,-1);
        return solve(res,nums,target);
    }
};