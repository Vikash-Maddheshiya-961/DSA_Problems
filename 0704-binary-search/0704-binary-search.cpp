class Solution {
public:
    void binary_search(vector<int>& nums,int lo, int hi, int target, int* ans){
        int mid = lo + (hi - lo)/2;
        if(lo > hi){
            *ans = -1;
            return;
        }
        if(nums[mid] == target){
            *ans = mid;
            return;
        }
        else if(nums[mid] < target) binary_search(nums,mid+1,hi,target,ans);
        else binary_search(nums,lo,mid-1,target,ans);
        return;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = -1;
        binary_search(nums,0,n-1,target,&ans);
        return ans;
    }
};