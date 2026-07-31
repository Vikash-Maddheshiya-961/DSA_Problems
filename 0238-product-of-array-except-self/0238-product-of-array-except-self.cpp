class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        int nzo = 0;
        for(int val:nums){
            if(val == 0) nzo++;
            else product *= val;
        }
        if(nzo > 1) product = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                nums[i] = product;
            }
            else if(nzo == 1){
                nums[i] = 0;
            }
            else{
                nums[i] = product / nums[i];
            }
        }
        return nums;
    }
};