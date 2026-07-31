class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if(nums.size()==1) return {};
        nums.push_back(-1);
        int i=0;
        while(i<nums.size()){
            if(nums[i] == i || nums[i] == -1 || nums[i] == nums[nums[i]]){
                i++;
            }
            else swap(nums[i],nums[nums[i]]);
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == -1) continue;
            if(nums[i] != i) ans.push_back(nums[i]);
        }
        return ans;
    }
};