class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1);
        int n = nums.size();
        int i=0;
        while(i<n){
            if(nums[i] == -1 || nums[i] == i) i++;
            else swap(nums[i],nums[nums[i]]);
        }
        int missing;
        for(int i=0;i<n;i++){
            if(nums[i] == -1){
                missing = i;
                break;
            }
        }
        return missing;
    }
};