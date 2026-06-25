class Solution {
public:
    void reverse_part(vector<int>& v,int i,int j){
        while(i<j){
            swap(v[i],v[j]);
            i++;
            j--;
        }
        return;
    }
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
            reverse_part(nums,0,n-1);
            return;
        }
        // 2.Reverse the array from pvt_idx+1 to n-1
        reverse_part(nums,pvt_idx+1,n-1);
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