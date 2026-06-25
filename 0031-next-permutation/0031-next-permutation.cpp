class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pvt_idx = -1;
        // 1.Find pivot index
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pvt_idx = i;
                break;
            }
        }
        // checking special case --> when pvt_idx if not found;
        if(pvt_idx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        // 2.Reverse the array from pvt_idx+1 to n-1
        reverse(nums.begin()+pvt_idx+1,nums.end());
        // 3.finding just greater element than pvt element
        int jst_max = -1;
        for(int i=pvt_idx+1;i<=n-1;i++){
            if(nums[i]>nums[pvt_idx]){
                jst_max = i;
                break;
            }
        }
        // 4.swap pivot and jst_maximum element
        swap(nums[pvt_idx],nums[jst_max]);
        return;
    }
};