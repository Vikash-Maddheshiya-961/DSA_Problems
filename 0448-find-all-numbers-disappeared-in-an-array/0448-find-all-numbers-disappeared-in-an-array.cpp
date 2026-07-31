class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        nums.push_back(-1);
        int i=0;
        while(i<nums.size()){
            if(nums[i] == -1 && i!=0) swap(nums[i],nums[0]);
            else if(nums[i] == i || nums[i] == -1 || nums[i] == nums[nums[i]]) i++;
            else swap(nums[i],nums[nums[i]]);
        }
        vector<int> ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != i) ans.push_back(i);
        }
        return ans;
    }
};