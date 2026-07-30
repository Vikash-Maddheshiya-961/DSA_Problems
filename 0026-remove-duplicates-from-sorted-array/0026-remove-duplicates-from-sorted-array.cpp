class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> dummy;
        dummy.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(dummy.back()!=nums[i]) dummy.push_back(nums[i]);
        }
        nums = dummy;
        return dummy.size();
    }
};