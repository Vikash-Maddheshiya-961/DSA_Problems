class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // using cycle sort
        int n = nums.size();
        int i=0;
        while(i<n){
            int actualIdx = nums[i];
            if(nums[i] == nums[actualIdx]) return nums[i];
            else swap(nums[i],nums[actualIdx]);
        }
        return -1;
    }
};