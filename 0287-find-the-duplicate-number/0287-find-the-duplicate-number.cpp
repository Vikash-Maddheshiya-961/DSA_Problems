class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i<n){
            if(i+1 == nums[i] || nums[nums[i]-1] == nums[i]) i++;
            else swap(nums[i],nums[nums[i]-1]);
        }

        for(int i=0;i<n;i++){
            if(i+1 != nums[i]) return nums[i];
        }

        return -1;
    }
};